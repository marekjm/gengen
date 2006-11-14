/*
 * Copyright (C) 2002  Lorenzo Bettini <http://www.lorenzobettini.it>
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

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "fileutil.h"

using namespace std;

void
open_input_file(const string &file_name)
{
  FILE *in = 0;

  in = freopen (file_name.c_str (), "r", stdin);
  if (!in)
    {
      cerr << "Error in opening " << file_name
           << " for input" << endl ;
      exit (EXIT_FAILURE);
    }
}

istream *
open_input_file_stream(const std::string &file_name)
{
  ifstream *sin = new ifstream(file_name.c_str());

  return sin;
}

ostream &
open_output_file(const string &file_name)
{
  ofstream *sout = new ofstream (file_name.c_str ());

  if ( ! *sout )
    {
      cerr << "Error in creating " << file_name << " for output" << endl ;
      exit (EXIT_FAILURE);
    }

  return *sout;
}

string
strip_file_path(const string &s)
{
  string::size_type pos_of_sep;

  pos_of_sep = s.rfind("/");
  if (pos_of_sep == string::npos)
    pos_of_sep = s.rfind("\\"); // try also with DOS path sep

  if (pos_of_sep == string::npos)
    return s; // no path

  return s.substr (pos_of_sep + 1);
}

const string
create_output_filename(const string &file_name, const string &ext)
{
  if (ext.length () != 0)
    {
      string _file_name;
      string::size_type dot_pos = file_name.rfind (".");
      if (dot_pos != string::npos && dot_pos != 0)
        _file_name = string (file_name, 0, dot_pos);
      else
        _file_name = file_name;

      return _file_name + "." + ext;
    }
  else
    return file_name;
}

