//
//
// C++ Implementation: skelstruct_strcnt
//
// Description: to compute the lenght of the string to be generated
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2003
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "skelstruct_strcnt.h"

SkelStructStrCnt::SkelStructStrCnt(const SkelStruct_C_Common &s) :
  SkelStruct_C_Common (s), length (0)
{
}

void
SkelStructStrCnt::call_external_function(ostream &stream, const string &name,
                                         unsigned int indent)
{
  variable_generation (stream, name, STRING_TYPE, indent);
}

void
SkelStructStrCnt::std_generation(ostream &stream, const string &s)
{
  int size = s.size();
  if (s == "\\n" || s == "\\t")
    size = 1;
  //std::cerr << "string: \"" << s << "\", length: " << size << std::endl;
  length += size;
}

void
SkelStructStrCnt::std_indentstr_generation(ostream &stream, const string &s,
                                           unsigned int indent)
{
  //std::cerr << "string: " << s << ", length: " << indent << std::endl;
  length += indent;
}

void
SkelStructStrCnt::indent_generation(ostream &stream, const string &ind)
{
}

void
SkelStructStrCnt::variable_generation(ostream &stream, const string &name,
                                      const skelitem_type &type,
                                      unsigned int indent)
{
  if (examined_variables.find (name) == examined_variables.end ())
    {
      string indent_string (indent, ' ');
      stream << indent_string;
      stream << "length += ";
      if (canBeString( type )) {
         stream << "(record->" << name << " ? " <<
             "strlen (record->" << name << ") : 0)";
      } else if (type == BOOL_TYPE) {
        stream << "strlen (bool_to_string (record->" << name
            << "))";
      } else if (type == INT_TYPE) {
        stream << "strlen (int_to_string (record->" << name
            << "))";
      }
      stream << " * " <<
         skel_struct->getVarOccurCnt(name) << ";\n";
      examined_variables.insert (name);
    }
}

void
SkelStructStrCnt::indent_update_generation(ostream &stream, int i)
{
}

int
SkelStructStrCnt::compute_length (ostream &stream, int indent)
{
  gen_generate_instructions (stream, indent);

  return length;
}

