
//
//
// C++ Interface: skelstruct_strcnt_lua
//
// Description: used for computing the length of the string to be generated for Lua
//
//
// Author: Raman Gopalan <ramangopalan@gmail.com>
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef SKELSTRUCT_STRCNT_LUA_H
#define SKELSTRUCT_STRCNT_LUA_H

#include "skelstruct_lua_common.h"

class SkelStructStrCntLua : public SkelStruct_Lua_Common
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
                                   const skelitem_type &t,
                                   unsigned int indent);
  virtual void indent_update_generation(ostream &stream, int i);
  virtual void indent_generation(ostream &stream, const string &ind);
  virtual string preformat(const string &item) { return item; }
  virtual void replace_chars(string &) {}

 public:
  SkelStructStrCntLua (const SkelStruct_Lua_Common &s);

  int compute_length (ostream &stream, int indent);
};

#endif // SKELSTRUCT_STRCNT_LUA_H

