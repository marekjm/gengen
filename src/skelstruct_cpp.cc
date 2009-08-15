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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif // HAVE_CONFIG_H

#include "gengen_globals.h"
#include "gengen_cmdline_options.h"
#include "skelstruct_cpp.h"
#include "setmethod.h"
#include "abstrmethod.h"
#include "callmeth.h"
#include "my_sstream.h"
#include "streamstruct.h"
#include "expressiongenerator_cpp.h"
#include "utils.h"
#include "fileutil.h"

#define class_suffix "_gen_class"

using std::endl;

SkelStructCpp::SkelStructCpp(SkelItems *items,
                             const string &name, const string &file_name,
                             StreamStruct &s, bool sep_files) :
  SkelStruct_C_Cpp_Common (items, name, file_name, s, sep_files)
{
}

SkelStructCpp::~SkelStructCpp()
{
}

void
SkelStructCpp::generate()
{
  if (num_of_methods < 0)
    analyze_items ();

  string class_name (name + class_suffix);
  string classname_include = class_name;

  Utils::toUpper( classname_include );

  class_gen_class::set_classname (class_name);
  cc_source_gen_class::set_classname (class_name);

  genmethod_gen_class::set_genname (name);
  cc_source_gen_class::set_genname (name);

  string author = "by " AUTHOR " " EMAIL;
  string other_comments =  HOMEPAGE;

  set_classnameinclude (classname_include + "_H");
  class_gen_class::set_package (PACKAGE);
  if (! no_gen_version)
    class_gen_class::set_version (VERSION);
  class_gen_class::set_author (author);
  class_gen_class::set_othercomments (other_comments);
  cc_source_gen_class::set_package (PACKAGE);
  if (! no_gen_version)
    cc_source_gen_class::set_version (VERSION);
  cc_source_gen_class::set_author (author);
  cc_source_gen_class::set_othercomments (other_comments);

  // make sure to strip possible path
  set_headerfile (strip_file_path(file_name));

  const string &init_defaults = generate_init_defaults();
  if (has_booleans() || has_ints())
  {
    set_hasinitializations(true);
    set_initdefaults(init_defaults);
  }

  if (has_fields())
  {
    set_memberwiseconstructor(true);
    set_params(generate_params());
    set_paramassignments(generate_paramassignments());
  }

  set_destructor(has_methods ());
  set_genstring(has_expand_strings());

  generate_class (*streamstruct.header_stream);

  streamstruct.header_stream->flush ();
}

ExpressionGeneratorCpp *SkelStructCpp::createExpGen(ostream &stream)
{
  return new ExpressionGeneratorCpp(stream);
}

void
SkelStructCpp::generate_fields(ostream &stream, unsigned int indent)
{
  VarSetIterator it;
  const VarSet &var_set = skel_struct->getVarSet();
  string indent_string (indent, ' ');
  skelitem_type item_type;

  for (it = var_set.begin (); it != var_set.end (); ++it)
    {
      item_type = (*it)->getType();
      if (canBeString( item_type ))
        {
          stream << indent_string;
          stream << "string " << **it << ";\n";
        }
      else if (item_type == BOOL_TYPE)
        {
          stream << indent_string;
          stream << "bool " << **it << ";\n";
        }
      else if (item_type == INT_TYPE)
        {
          stream << indent_string;
          stream << "int " << **it << ";\n";
        }
    }
}

const string
SkelStructCpp::generate_init_defaults()
{
  VarSetIterator it;
  const VarSet &var_set = skel_struct->getVarSet();
  bool first = true;
  skelitem_type item_type;
  ostringstream init_defaults;

  for (it = var_set.begin (); it != var_set.end (); ++it)
    {
      item_type = (*it)->getType ();
      if (item_type == BOOL_TYPE || item_type == INT_TYPE)
        {
          if (first)
          {
            first = false;
          }
          else
            init_defaults << ", ";

          // initialization for booleans is false and for ints is 0
          init_defaults << **it << " (" <<
              (item_type == BOOL_TYPE ? "false" : "0") << ")";
        }
    }

  return init_defaults.str();
}

const string
SkelStructCpp::generate_params()
{
  VarSetIterator it;
  const VarSet &var_set = skel_struct->getVarSet();
  bool first = true;
  skelitem_type item_type;
  ostringstream stream;

  for (it = var_set.begin (); it != var_set.end (); ++it)
    {
      item_type = (*it)->getType ();
      if (isVariableType( item_type ))
        {
          if (first)
            first = false;
          else
            stream << ", ";

          if (item_type == BOOL_TYPE)
            stream << "bool _" << **it;
          else if (item_type == INT_TYPE)
            stream << "int _" << **it;
          else
            stream << "const string &_" << **it;
        }
    }

  return stream.str();
}

const string
SkelStructCpp::generate_paramassignments()
{
  VarSetIterator it;
  const VarSet &var_set = skel_struct->getVarSet();
  bool first = true;
  skelitem_type item_type;
  ostringstream stream;

  for (it = var_set.begin (); it != var_set.end (); ++it)
    {
      item_type = (*it)->getType ();
      if (isVariableType( item_type ))
        {
          if (first)
            first = false;
          else
            stream << ", ";

          stream << **it << " (_" << **it << ")";
        }
    }

  return stream.str();
}

void
SkelStructCpp::generate_setmethods(ostream &stream, unsigned int indent)
{
  VarSetIterator it;
  const VarSet &var_set = skel_struct->getVarSet();
  skelitem_type item_type;
  setmethod_gen_class setmethod_gen;
  abstrmethod_gen_class abstrmethod_gen;
  string indent_string (indent, ' ');

  for (it = var_set.begin (); it != var_set.end (); ++it)
    {
      item_type = (*it)->getType ();

      if (item_type == METHOD_TYPE)
        {
          stream << indent_string;
          abstrmethod_gen.set_name ((*it)->getText ());
          abstrmethod_gen.generate_abstrmethod (stream, indent);

          stream << endl;
          stream << endl;
        }

      stream << indent_string;
      if (item_type == BOOL_TYPE)
        setmethod_gen.set_type ("bool ");
      else if (item_type == INT_TYPE)
        setmethod_gen.set_type ("int ");
      else
        setmethod_gen.set_type ("const string &");
      setmethod_gen.set_name ((*it)->getText ());
      setmethod_gen.generate_setmethod (stream, indent);

      stream << endl;
      stream << endl;
    }
}

void
SkelStructCpp::generate_generate(ostream &stream, unsigned int indent)
{
  if (sep_files)
    set_methend (";");

  generate_genmethod (stream, indent);
}

void
SkelStructCpp::generate_genmethbody(ostream &stream, unsigned int indent)
{
  if (sep_files)
    {
      generate_cc_source (*streamstruct.source_stream);

      streamstruct.source_stream->flush ();
    }
  else
    generate_genmethod_body (stream, indent);
}

void
SkelStructCpp::generate_methodbody(ostream &stream, unsigned int indent)
{
  generate_genmethod_body (stream, indent);
}

void
SkelStructCpp::generate_geninstructions(ostream &stream, unsigned int indent)
{
  gen_generate_instructions (stream, indent);
}

void
SkelStructCpp::call_external_function(ostream &stream, const string &name,
                                      unsigned int indent)
{
  callmeth_gen_class callmeth;
  callmeth.set_name (name);
  callmeth.generate_callmeth (stream, indent);
  stream << endl;
}

void
SkelStructCpp::std_generation(ostream &stream, const string &s)
{
  stream << "stream << " << s << ";\n";
}

void
SkelStructCpp::variable_generation(ostream &stream, const string &name,
                                   const skelitem_type &t,
                                   unsigned int indent)
{
  if (expand_tabs)
    stream << "generate_string (" + name +
      ", stream, indent + indent_str.length ());\n";
  else {
    if (t == BOOL_TYPE) // make sure to print true or false, instead of 1 or 0
      std_generation (stream, "std::boolalpha << " + name);
    else
      std_generation (stream, name);
  }
}
