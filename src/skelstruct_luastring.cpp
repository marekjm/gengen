
//
// C++ Implementation: skelstruct_luastring
//
// Description: generate into a Lua string instead of into a file
//
//
// Author: Raman Gopalan <ramangopalan@gmail.com>
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "skelstruct_luastring.h"

SkelStructLuaString::SkelStructLuaString(const SkelStruct_Lua_Common &s) :
  SkelStruct_Lua_Common (s)
{
  do_indent_update = false;
}

void
SkelStructLuaString::call_external_function(ostream &stream, const string &name,
                                            unsigned int indent)
{
  variable_generation (stream, name, STRING_TYPE, indent);
}

void
SkelStructLuaString::std_generation(ostream &stream, const string &s)
{
  stream << "output = output .. " << s << "\n";
}

void
SkelStructLuaString::variable_generation(ostream &stream, const string &name,
                                         const skelitem_type &type,
                                         unsigned int indent)
{
  if (canBeString( type )) {
    stream << "if (record." << name << ") then ";
    std_generation (stream, "record." + name + " end");
  } else if (type == BOOL_TYPE) {
    std_generation (stream, "bool_to_string(record." + name + ")");
  } else if (type == INT_TYPE) {
    std_generation (stream, "int_to_string(record." + name + ")");
  }
}

void
SkelStructLuaString::start_generation(ostream &stream, unsigned int indent)
{
  gen_generate_instructions (stream, indent);
}

