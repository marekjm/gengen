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

#ifndef SKELSTRUCT_H
#define SKELSTRUCT_H

#include <iostream>
#include <string>
#include <set>

using std::string;
using std::ostream;

#include "skelitems.hpp"
#include "varitem.h"

#define CALLEXTERNAL_PREFIX "generate_"
#define STRCNT_PREFIX "strcnt_"

#include "typemap.h"

class StreamStruct;
class ExpressionChecker;

/**
 * This class is required only because for the moment multimethods
 * processed by doublecpp require pointers as parameters (and cannot
 * be typedefs, as ostream)
 */
#line 46 "skelstruct.h"
class OstreamInfo
{
public:
 ostream &stream;
 unsigned int indent;

 OstreamInfo(ostream &s, unsigned int i) : stream(s), indent(i) {}
};


// doublecpp: forward declarations, DO NOT MODIFY
class BinaryExpression; // file: binaryexpression.h
class Expression; // file: expression.h
class IfStruct; // file: ifstruct.h
class OstreamInfo; // file: skelstruct.h
class SkelItemStruct; // file: skelitemstruct.h
class UnaryExpression; // file: unaryexpression.h
class VarItem; // file: varitem.h
// doublecpp: end, DO NOT MODIFY

#line 56 "skelstruct.h"
class SkelStruct
{
 protected:
  typedef std::set<SkelItemStruct> VarItemSet;
  VarItemSet vars;

  SkelItems *skel_struct;
  ExpressionChecker *expressionChecker;
  
  static TypeMap typeMap;

  string name;
  string file_name;
  StreamStruct &streamstruct;
  bool sep_files;

  int num_of_methods;
  int num_of_normal_strings;
  int num_of_booleans;
  int num_of_ints;
  /// whether there are boolean variables that must be generated,
  /// i.e., they don't appear only as if expressions
  int num_of_booleans_to_generate;
  /// whether there are integer variables that must be generated,
  /// i.e., they don't appear only as if expressions
  int num_of_ints_to_generate;
  
  /// whether we're inspecting an if expression
  bool inspecting_if_expression;

  bool is_copy; // wether this is created from a copy
  bool do_indent_update; // whether we have to update the indent counter

  bool has_methods() const; // whether there's an item with type "method"
  bool has_normal_strings() const; // whether there's a normal item
  bool has_booleans() const; // whether there's a boolean item
  bool has_ints() const; // whether there's an int item
  bool has_booleans_to_generate() const; // whether there's a boolean item to generate
  bool has_ints_to_generate() const; // whether there's an int item to generate
  bool has_fields() const; // whether there will be fields to generate
  bool has_expand_strings() const; // whether some strings have to be expanded
  static bool all_spaces(const SkelItemStruct *);
  // the item is made of only spaces

  void analyze_items();
  void analyze_items(const SkelItems *);

  void check_variable(const SkelItemStruct *);
  
  /**
   * Records the occurrence of the passed type
   * @param type The type whose occurrences must be counted
   * @param to_generate Whether this type represents something to actually
   * generate, e.g., not an if expression
   */
  void count_type(skelitem_type type, bool to_generate);

// doublecpp: method branches, DO NOT MODIFY
#line 114 "skelstruct.h"
virtual void analyze_item(SkelItemStruct * v);
#line 115 "skelstruct.h"
virtual void analyze_item(VarItem * v);
#line 116 "skelstruct.h"
virtual void analyze_item(Expression * e);
#line 117 "skelstruct.h"
virtual void analyze_item(UnaryExpression * exp);
#line 118 "skelstruct.h"
virtual void analyze_item(BinaryExpression * exp);
#line 119 "skelstruct.h"
virtual void analyze_item(IfStruct * i);
public:
void _forward_analyze_item(BinaryExpression * exp)
{
  analyze_item(exp);
};

void _forward_analyze_item(Expression * e)
{
  analyze_item(e);
};

void _forward_analyze_item(IfStruct * i)
{
  analyze_item(i);
};

void _forward_analyze_item(SkelItemStruct * v)
{
  analyze_item(v);
};

void _forward_analyze_item(UnaryExpression * exp)
{
  analyze_item(exp);
};

void _forward_analyze_item(VarItem * v)
{
  analyze_item(v);
};

protected:
virtual void analyze_item_DB(SkelItemStruct * v);
#line 119 "skelstruct.h"
// doublecpp: end, DO NOT MODIFY


// doublecpp: method branches, DO NOT MODIFY
#line 123 "skelstruct.h"
virtual void pre_process(SkelItemStruct * s, OstreamInfo * o);
#line 124 "skelstruct.h"
virtual void pre_process(VarItem * v, OstreamInfo * o);
#line 125 "skelstruct.h"
virtual void pre_process(IfStruct * i, OstreamInfo * o);
public:
void _forward_pre_process(IfStruct * i, OstreamInfo * o)
{
  pre_process(i, o);
};

void _forward_pre_process(SkelItemStruct * s, OstreamInfo * o)
{
  pre_process(s, o);
};

void _forward_pre_process(VarItem * v, OstreamInfo * o)
{
  pre_process(v, o);
};

protected:
virtual void pre_process_DB(SkelItemStruct * s, OstreamInfo * o);
#line 125 "skelstruct.h"
// doublecpp: end, DO NOT MODIFY


  SkelItemStruct *get_prev_item (SkelItems::iterator &it, const SkelItems *);
  SkelItemStruct *get_next_item (SkelItems::iterator &it, const SkelItems *);
  
  /**
   * Whether the passed type represents a valid type for a variable
   * 
   * @param t the type to examine 
   * @return true if the type is a valid type for a variable
   */
  static bool isVariableType(skelitem_type t) ;

  /**
   * Whether the passed type can require generation of a string
   * variable
   * 
   * @param t the type to examine 
   * @return true if the type can require generation of a string
   * variable
   */
  static bool canBeString(skelitem_type t) ;

  // called when we have to generate a call to an external function/method
  virtual void call_external_function(ostream &stream, const string &name,
                                      unsigned int indent) = 0;

  // called when we have to generate an ordinary generation instruction
  virtual void std_generation(ostream &stream, const string &name) = 0;

  // called when we have to generate an indent_str generation instruction
  virtual void std_indentstr_generation(ostream &stream, const string &name,
                                        unsigned int indent);

  // called when we have to generate a variable generation instruction
  virtual void variable_generation(ostream &stream, const string &name,
                                   skelitem_type t,
                                   unsigned int indent) = 0;

  // called when we have to generate an if instruction
  virtual void if_generation(const string &exp, const string &then_branch,
                             const string &else_branch, ostream &stream,
                             unsigned int indent) = 0;
  
  /**
   * This method is called when an expression must be translated in the
   * target language
   * 
   * @param exp The expression to translate
   * @param stream The stream where it must be translated
   */
  virtual void exp_generation(Expression *exp, ostream &stream) = 0;

  // called when we have to update the indent counter
  virtual void indent_update_generation(ostream &stream, int i);

  // called when we have to indent
  virtual void indent_generation(ostream &stream, const string &ind);

  virtual void gen_generate_instructions(ostream &stream, unsigned int indent);
  virtual void gen_generate_instructions(const SkelItems *, ostream &stream, unsigned int indent);
  virtual string preformat(const string &item);
  virtual void replace_char(string &, char c, const string &s);
  virtual void replace_chars(string &);

 public:
  SkelStruct(SkelItems *items, const string &n, const string &file, StreamStruct &s, bool sep);
  SkelStruct(const SkelStruct &c);

  virtual ~SkelStruct() ;

  virtual void generate();
};

#endif // SKELSTRUCT_H
