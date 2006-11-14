//
// C++ Implementation: skelstruct_cstring
//
// Description: generate into a C string instead of into a file
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2003
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "skelstruct_cstring.h"

SkelStructCString::SkelStructCString(const SkelStruct_C_Common &s) :
  SkelStruct_C_Common (s)
{
  do_indent_update = false;
}

void
SkelStructCString::call_external_function(ostream &stream, const string &name,
                                         unsigned int indent)
{
  variable_generation (stream, name, STRING_TYPE, indent);
}

void
SkelStructCString::std_generation(ostream &stream, const string &s)
{
  stream << "strcat (output, " << s << ");\n";
}

void
SkelStructCString::variable_generation(ostream &stream, const string &name,
                                       skelitem_type type,
                                       unsigned int indent)
{
  if (canBeString( type )) {
    stream << "if (record->" << name << ") ";
    std_generation (stream, "record->" + name);
  } else if (type == BOOL_TYPE) {
    std_generation (stream, "bool_to_string (record->" + name + ")");
  } else if (type == INT_TYPE) {
    std_generation (stream, "int_to_string (record->" + name + ")");
  }
}

void
SkelStructCString::start_generation (ostream &stream, unsigned int indent)
{
  gen_generate_instructions (stream, indent);
}

