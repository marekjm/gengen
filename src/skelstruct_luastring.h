
//
// C++ Interface: skelstruct_luastring
//
// Description: generate into a Lua string instead of into a file
//
//
// Author: Raman Gopalan <ramangopalan@gmail.com>
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef SKELSTRUCT_LUASTRING_H
#define SKELSTRUCT_LUASTRING_H

#include "skelstruct_lua_common.h"

class SkelStructLuaString : public SkelStruct_Lua_Common
{
 public:
  // redefined from SkelStruct
  virtual void call_external_function(ostream &stream, const string &name,
                                      unsigned int indent);
  virtual void std_generation(ostream &stream, const string &s);
  virtual void variable_generation(ostream &stream, const string &name,
                                   const skelitem_type &t,
                                   unsigned int indent);

 public:
  SkelStructLuaString (const SkelStruct_Lua_Common &s);

  void start_generation (ostream &stream, unsigned int indent);
};

#endif // SKELSTRUCT_LUASTRING_H
