/*
 * File automatically generated by
 * gengen 1.0 by Lorenzo Bettini 
 * http://www.gnu.org/software/gengen
 */

#ifndef SETMETHOD_GEN_CLASS_H
#define SETMETHOD_GEN_CLASS_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class setmethod_gen_class
{
 protected:
  string name;
  string type;

 public:
  setmethod_gen_class()
  {
  }
  
  setmethod_gen_class(const string &_name, const string &_type) :
    name (_name), type (_type)
  {
  }

  static void
  generate_string(const string &s, ostream &stream, unsigned int indent)
  {
    if (!indent || s.find('\n') == string::npos)
      {
        stream << s;
        return;
      }

    string::size_type pos;
    string::size_type start = 0;
    string ind (indent, ' ');
    while ( (pos=s.find('\n', start)) != string::npos)
      {
        stream << s.substr (start, (pos+1)-start);
        start = pos+1;
        if (start+1 <= s.size ())
          stream << ind;
      }
    if (start+1 <= s.size ())
      stream << s.substr (start);
  }

  void set_name(const string &_name)
  {
    name = _name;
  }

  void set_type(const string &_type)
  {
    type = _type;
  }

  void generate_setmethod(ostream &stream, unsigned int indent = 0)
  {
    string indent_str (indent, ' ');
    indent = 0;
  
    stream << "void set_";
    generate_string (name, stream, indent + indent_str.length ());
    stream << "(";
    generate_string (type, stream, indent + indent_str.length ());
    stream << "_";
    generate_string (name, stream, indent + indent_str.length ());
    stream << ")";
    stream << "\n";
    stream << indent_str;
    stream << "{";
    stream << "\n";
    stream << indent_str;
    indent = 2;
    stream << "  ";
    generate_string (name, stream, indent + indent_str.length ());
    stream << " = _";
    generate_string (name, stream, indent + indent_str.length ());
    stream << ";";
    indent = 0;
    stream << "\n";
    stream << indent_str;
    stream << "}";
  }
};

#endif // SETMETHOD_GEN_CLASS_H