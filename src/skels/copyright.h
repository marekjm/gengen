/*
 * File automatically generated by
 * gengen 1.0 by Lorenzo Bettini 
 * http://www.gnu.org/software/gengen
 */

#ifndef COPYRIGHT_GEN_CLASS_H
#define COPYRIGHT_GEN_CLASS_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class copyright_gen_class
{
 protected:
  string year;

 public:
  copyright_gen_class()
  {
  }
  
  copyright_gen_class(const string &_year) :
    year (_year)
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

  void set_year(const string &_year)
  {
    year = _year;
  }

  void generate_copyright(ostream &stream, unsigned int indent = 0)
  {
    string indent_str (indent, ' ');
    indent = 0;
  
    stream << "Copyright (C) ";
    generate_string (year, stream, indent + indent_str.length ());
    stream << "  Lorenzo Bettini <http://www.lorenzobettini.it>";
    stream << "\n";
    stream << indent_str;
    stream << "This program comes with ABSOLUTELY NO WARRANTY; for details";
    stream << "\n";
    stream << indent_str;
    stream << "please see the file 'COPYING' supplied with the source code.";
    stream << "\n";
    stream << indent_str;
    stream << "This is free software, and you are welcome to redistribute it";
    stream << "\n";
    stream << indent_str;
    stream << "under certain conditions; again, see 'COPYING' for details.";
    stream << "\n";
    stream << indent_str;
    stream << "This program is released under the GNU General Public License.";
    stream << "\n";
    stream << indent_str;
  }
};

#endif // COPYRIGHT_GEN_CLASS_H