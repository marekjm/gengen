//
//
// C++ Interface: skelstruct_strcnt
//
// Description: used for computing the length of the string to be generated
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2003
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef SKELSTRUCT_STRCNT_H
#define SKELSTRUCT_STRCNT_H

#include "skelstruct_c_common.h"

class SkelStructStrCnt : public SkelStruct_C_Common
{
 protected:
  int length;
  set<string> examined_variables;

 public:
  // redefined from SkelStruct
  virtual void call_external_function(ostream &stream, const string &name,
                                      unsigned int indent);
  virtual void std_generation(ostream &stream, const string &s);
  virtual void std_indentstr_generation(ostream &stream, const string &name,
                                        unsigned int indent);
  virtual void variable_generation(ostream &stream, const string &name,
                                   skelitem_type t,
                                   unsigned int indent);
  virtual void indent_update_generation(ostream &stream, int i);
  virtual void indent_generation(ostream &stream, const string &ind);
  virtual string preformat(const string &item) { return item; }
  virtual void replace_chars(string &) {}
  
 public:
  SkelStructStrCnt (const SkelStruct_C_Common &s);

  int compute_length (ostream &stream, int indent);
};

#endif // SKELSTRUCT_STRCNT_H
