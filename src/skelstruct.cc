/*
 * Copyright (C) 2002 Lorenzo Bettini <http://www.lorenzobettini.it>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#include "skelstruct.hpp"
#include "ifstruct.h"
#include "gengen_cmdline_options.h"
#include "my_sstream.h"
#include "expression.h"
#include "expressionchecker.h"
#include "unaryexpression.h"
#include "binaryexpression.h"
#include "stringutil.h"
#include "errormanager.h"
#include "streamstruct.h"

#include <algorithm>
#include <functional>

using std::endl;

TypeMap SkelStruct::typeMap;

SkelStruct::SkelStruct(SkelItems *items, const string &n, const string &file, StreamStruct &s, bool sep)
  : skel_struct (items), expressionChecker (new ExpressionChecker()),
    name (n), file_name (file), streamstruct (s), sep_files (sep),
    num_of_methods (-1),
    num_of_normal_strings (-1),
    num_of_booleans (-1),
    num_of_ints (-1),
    num_of_booleans_to_generate (-1),
    num_of_ints_to_generate (-1),
    inspecting_if_expression (false),
    is_copy (false),
    do_indent_update (true)
{
}

SkelStruct::SkelStruct(const SkelStruct &c) :
    skel_struct (new SkelItems(*(c.skel_struct))),
    expressionChecker (new ExpressionChecker()),
    name (c.name), file_name (c.file_name),
    streamstruct (c.streamstruct), sep_files (c.sep_files),
    num_of_methods (-1), num_of_normal_strings (-1),
    num_of_booleans (-1),
    num_of_ints (-1),
    num_of_booleans_to_generate (-1),
    num_of_ints_to_generate (-1),
    inspecting_if_expression (false),
    is_copy (true),
    do_indent_update (c.do_indent_update)
{
}

SkelStruct::~SkelStruct()
{
  delete skel_struct;
  delete expressionChecker;
}

void
SkelStruct::generate()
{
  SkelItems::iterator it;

  std::for_each(skel_struct->begin (), skel_struct->end (),
                std::bind2nd(
                    std::mem_fun(&SkelItemStruct::output), streamstruct.header_stream));
}

// skip spaces
SkelItemStruct *
SkelStruct::get_prev_item(SkelItems::iterator &it, const SkelItems *items)
{
  SkelItems::iterator tit = it;
  SkelItemStruct *item = *it;

  if (tit != items->begin ())
    {
      while (--tit != items->begin ())
        {
          item = *tit;
          if (! all_spaces (item))
            break;
        }
    }

  return item;
}

// skip spaces
SkelItemStruct *
SkelStruct::get_next_item(SkelItems::iterator &it, const SkelItems *items)
{
  SkelItems::iterator tit = it;
  SkelItemStruct *item = *it;

  if (tit != items->end ())
    {
      while (++tit != items->end ())
        {
          item = *tit;
          if (! all_spaces (item))
            break;
        }
    }

  return item;
}

bool SkelStruct::isVariableType(skelitem_type item_type)
{
  return (item_type == NOTYPE || item_type == METHOD_TYPE || 
          item_type == BOOL_TYPE || item_type == INT_TYPE ||
          item_type == STRING_TYPE);
} 

bool SkelStruct::canBeString(skelitem_type item_type)
{
  return (item_type == NOTYPE || item_type == METHOD_TYPE || 
          item_type == STRING_TYPE);
} 

bool
SkelStruct::all_spaces(const SkelItemStruct *item)
{
  return (item->getText()).find_first_not_of (' ') == string::npos;
}

bool
SkelStruct::has_methods() const
{
  return (num_of_methods > 0);
}

bool
SkelStruct::has_normal_strings() const
{
  return (num_of_normal_strings > 0);
}

bool
SkelStruct::has_booleans() const
{
  return (num_of_booleans > 0);
}

bool
SkelStruct::has_ints() const
{
  return (num_of_ints > 0);
}

bool
SkelStruct::has_booleans_to_generate() const
{
  return (num_of_booleans_to_generate > 0);
}

bool
SkelStruct::has_ints_to_generate() const
{
  return (num_of_ints_to_generate > 0);
}

bool
SkelStruct::has_fields() const
{
  return (has_normal_strings() || has_booleans() || has_ints());
}

bool
SkelStruct::has_expand_strings() const
{
  return (has_methods () || (expand_tabs && has_normal_strings ()));
}

void
SkelStruct::analyze_items()
{
  num_of_methods = 0;
  num_of_normal_strings = 0;
  num_of_booleans = 0;
  num_of_ints = 0;
  num_of_booleans_to_generate = 0;
  num_of_ints_to_generate = 0;
  inspecting_if_expression = false;

  analyze_items (skel_struct);
}

void
SkelStruct::analyze_items(const SkelItems *items)
{
  SkelItems::iterator it;

  std::for_each(items->begin (), items->end (),
                std::bind1st(std::mem_fun(&SkelStruct::analyze_item_DB), this));
}

void
SkelStruct::analyze_item(VarItem *var)
{
  // pass true since this is a varitem, thus it is something
  // that will be actually generated in the output
  count_type( var->getType (), true );

  check_variable(var);
}

void SkelStruct::count_type( skelitem_type type, bool to_generate )
{
  if (type == METHOD_TYPE) {
    ++num_of_methods;
  } else if (type == BOOL_TYPE) {
    ++num_of_booleans;
    if (to_generate)
      ++num_of_booleans_to_generate;
  } else if (type == INT_TYPE) {
    ++num_of_ints;
    if (to_generate)
      ++num_of_ints_to_generate;
  } else
    ++num_of_normal_strings;
}

void
SkelStruct::check_variable(const SkelItemStruct *var)
{
  VarItemSet::const_iterator v = vars.find(*var);
  if (v != vars.end() && v->getType() != var->getType())
    {
      print_error("variable \"" + v->getText() + "\" of type \"" + 
          typeMap[var->getType()] + "\"", var);
      print_error("already used with another type", var);
      print_error("previous usage was here with type \"" + typeMap[v->getType()] + "\"", *v);
      exit_failure();
    }
  else
    vars.insert(*var);
}

void
SkelStruct::analyze_item(Expression *e)
{
  // if the expression is const then it's not a variable
  // and we don't check it
  if (! e->isConst())
    check_variable(e);
  
  // pass false since an expression will not be actually generated
  // in the output, but will be used only to test something
  count_type( e->getExpressionType(), false );
}

void
SkelStruct::analyze_item(UnaryExpression *e)
{
  analyze_item_DB(e->getSubExpression());
}

void
SkelStruct::analyze_item(BinaryExpression *e)
{
  analyze_item_DB(e->getLeftExpression());
  analyze_item_DB(e->getRightExpression());
}

void
SkelStruct::analyze_item(IfStruct *ifstruct)
{
  Expression *exp = ifstruct->getExpression();
  if (exp) {
    expressionChecker->resetError();
    expressionChecker->visit_DB( exp );
    const string &error = expressionChecker->getError();
    if (error != "") {
      print_error( error, exp );
      exit_failure();
    }
    analyze_item_DB(exp);
    
    // now check that exp has actually type bool
    if (exp->getType() != BOOL_TYPE) {
      print_error("boolean expression expected instead of type \"" +
          typeMap[exp->getType()] + "\"", exp);
      exit_failure();
    }
  }

  const SkelItems *then_branch = ifstruct->getThenBranch();
  if (then_branch)
    analyze_items(then_branch);

  IfStruct *else_branch = ifstruct->getElseBranch();
  if (else_branch)
    analyze_item (else_branch);
}

void
SkelStruct::analyze_item(SkelItemStruct *)
{
}

void
SkelStruct::gen_generate_instructions(ostream &stream, unsigned int indent)
{
  gen_generate_instructions (skel_struct, stream, indent);
}

void
SkelStruct::gen_generate_instructions(const SkelItems *items, ostream &stream, unsigned int indent)
{
  SkelItems::iterator it;
  bool found_newline = false;
  bool generate = true;
  bool start_of_line = true;
  bool indent_updated = false;
  SkelItemStruct *item = 0;
  SkelItemStruct *next_item = 0;
  SkelItemStruct *prev_item = 0;
  string indent_string (indent, ' ');
  OstreamInfo os (stream, indent);

  stream << endl;

  for (it = items->begin (); it != items->end (); ++it)
    {
      item = *it;
      if (item->isToBePreProcessed ())
        {
          pre_process_DB(item, &os);

          start_of_line = false;
        }
      else
        {
          if (item->getText () != "\n")
            {
              found_newline = false;

              if (do_indent_update && all_spaces(item) && start_of_line)
                {
                  // all spaces: update indent
                  indent_generation (stream, indent_string);
                  indent_update_generation
                    (stream, (item->getText()).length ());
                  indent_updated = true;
                }

              start_of_line = false;
            }
          else
            {
              found_newline = true;
              start_of_line = true;
              if (indent_updated)
                {
                  // bring the additional indent back to 0
                  indent_generation (stream, indent_string);
                  indent_update_generation (stream, 0);
                  indent_updated = false;
                }
            }

          generate = true;

          if (all_spaces (item))
            {
              next_item = get_next_item (it, items);
              if (next_item->getOptions().iteration)
                generate = false;
            }
          else if (found_newline)
            {
              prev_item = get_prev_item (it, items);
              if (prev_item->getOptions().iteration)
                generate = false;
            }

          if (generate)
            {
              indent_generation (stream, indent_string);
              string line_gen;

              if (found_newline)
                line_gen = preformat ("\\n");
              else
                {
                  string line = item->getText(); // copy
                  replace_chars (line);
                  line_gen = preformat (line);
                }

              std_generation (stream, line_gen);
            }

          if (found_newline)
            {
              indent_generation (stream, indent_string);
              std_indentstr_generation (stream, "indent_str", indent);
            }
        }
    }
}

void
SkelStruct::pre_process(SkelItemStruct *, OstreamInfo *)
{
}

void
SkelStruct::pre_process(VarItem *var, OstreamInfo *os)
{
  skelitem_type item_type = var->getType ();
  string indent_string (os->indent, ' ');
  indent_generation (os->stream, indent_string);

  if (item_type == METHOD_TYPE)
    call_external_function
     (os->stream, var->getText (), os->indent);
  else
    variable_generation (os->stream, var->getText (), var->getType(), os->indent);
}

void
SkelStruct::pre_process(IfStruct *ifstruct, OstreamInfo *os)
{
  string indent_string (os->indent, ' ');
  indent_generation (os->stream, indent_string);

  Expression *exp = ifstruct->getExpression();
  if (! exp) // it's simply an else branch
    {
      const SkelItems *then_branch = ifstruct->getThenBranch();
      if (then_branch)
        gen_generate_instructions (then_branch, os->stream, 0);

      return;
    }

  ostringstream then_s;
  ostringstream else_s;
  ostringstream exp_stream;
  
  exp_generation( exp, exp_stream );
  
  string exp_s = exp_stream.str();

  const SkelItems *then_branch = ifstruct->getThenBranch();
  if (then_branch)
    gen_generate_instructions (then_branch, then_s, 0);

  IfStruct *else_branch = ifstruct->getElseBranch();
  if (else_branch)
    {
      OstreamInfo os_else (else_s, 0);
      pre_process (else_branch, &os_else);
    }

  if_generation (exp_s, trim(then_s.str()), trim(else_s.str()), os->stream, os->indent);
}

void
SkelStruct::std_indentstr_generation(ostream &stream, const string &name,
                                     unsigned int indent)
{
  std_generation (stream, name);
}

void
SkelStruct::indent_update_generation(ostream &stream, int i)
{
  stream << "indent = " << i << ";\n";
}

void
SkelStruct::indent_generation(ostream &stream, const string &ind)
{
  stream << ind;
}

string
SkelStruct::preformat(const string &item)
{
  string line = item; // make a copy
  line = "\"" + line + "\"";

  return line;
}

void
SkelStruct::replace_chars(string &line)
{
  replace_char (line, '\\', "\\\\");
  replace_char (line, '\"', "\\\"");
}

void
SkelStruct::replace_char(string &text, char repl, const string &with)
{
  string::size_type it;

  it = text.find (repl);

  while (it != string::npos)
    {
      text.replace (it, 1, with);
      it = text.find (repl, it + with.size ());
    }
}
