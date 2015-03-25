
//
//
// C++ Implementation: skelstruct_strcnt_lua
//
// Description: to compute the lenght of the string to be generated
//
//
// Author: Raman Gopalan <ramangopalan@gmail.com>
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "skelstruct_strcnt_lua.h"

SkelStructStrCntLua::SkelStructStrCntLua(const SkelStruct_Lua_Common &s) :
  SkelStruct_Lua_Common (s), length (0)
{
}

void
SkelStructStrCntLua::call_external_function(ostream &stream, const string &name,
                                            unsigned int indent)
{
  variable_generation (stream, name, STRING_TYPE, indent);
}

void
SkelStructStrCntLua::std_generation(ostream &stream, const string &s)
{
  int size = s.size();
  if (s == "\\n" || s == "\\t")
    size = 1;
  //std::cerr << "string: \"" << s << "\", length: " << size << std::endl;
  length += size;
}

void
SkelStructStrCntLua::std_indentstr_generation(ostream &stream, const string &s,
                                              unsigned int indent)
{
  //std::cerr << "string: " << s << ", length: " << indent << std::endl;
  length += indent;
}

void
SkelStructStrCntLua::indent_generation(ostream &stream, const string &ind)
{
}

void
SkelStructStrCntLua::variable_generation(ostream &stream, const string &name,
                                         const skelitem_type &type,
                                         unsigned int indent)
{
  if (examined_variables.find (name) == examined_variables.end ())
    {
      string indent_string (indent, ' ');
      stream << indent_string;
      stream << "length = length + ";
      if (canBeString( type )) {
         stream << "((record." << name << ") " <<
             "and string.len(record." << name << ") or 0)";
      } else if (type == BOOL_TYPE) {
        stream << "string.length(bool_to_string(record." << name
            << "))";
      } else if (type == INT_TYPE) {
        stream << "string.len(int_to_string(record." << name
            << "))";
      }
      stream << " * " <<
         skel_struct->getVarOccurCnt(name) << ";\n";
      examined_variables.insert (name);
    }
}

void
SkelStructStrCntLua::indent_update_generation(ostream &stream, int i)
{
}

int
SkelStructStrCntLua::compute_length (ostream &stream, int indent)
{
  gen_generate_instructions (stream, indent);

  return length;
}

