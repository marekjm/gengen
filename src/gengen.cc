/*
 * Copyright (C) 2002-2010  Lorenzo Bettini <http://www.lorenzobettini.it>
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "skelstruct.hpp"
#include "skelfactory_cpp.h"
#include "skelfactory_c.h"
#include "skelfactory_lua.h"
#include "mainskelstruct.h"
#include "mainskelfactory.h"
#include "cmdline.h"
#include "fileutil.h"
#include "sourcename.h"
#include "copyright.h"
#include "gengen_cmdline_options.h"
#include "streamstruct.h"
#include "my_sstream.h"

extern int yyparse() ;

SkelStruct *skel_struct = 0;
SkelItems *skel_items = 0;
SkelFactory *skel_factory = 0;

string input_file;
string stripped_input_file;

using namespace std;

static void
gengen_error(const string &s);

static void
generate_code(const ostringstream &stream, const string &file_name);

gengetopt_args_info args_info;

int
main(int argc, char **argv)
{
  if(cmdline_parser(argc, argv, &args_info) != 0)
    // calls cmdline parser. The user gived bag args if it doesn't return -1
    return 1;

  if (args_info.help_given)
  {
    cout << "GNU ";
    cmdline_parser_print_help ();
    cout << endl;
    cout << "Report bugs to Lorenzo Bettini <http://www.lorenzobettini.it> " << endl;
    exit (0);
  }

  if (args_info.version_given)
  {
    cout << "GNU ";
    cmdline_parser_print_version ();
    copyright_gen_class copyright;
    copyright.set_year ("2002-2009");
    copyright.generate_copyright (cout);
    exit (0);
  }

  string gen_name;
  string file_name;

  gen_name = string (args_info.gen_name_arg);

  expand_tabs = (args_info.expand_tabs_given != 0);
  no_gen_version = (args_info.no_gen_version_given != 0);

  if (args_info.test_mode_given)
    test_mode = true;

  if (args_info.file_name_given)
    file_name = string (args_info.file_name_arg);

  if (args_info.output_dir_given)
	  file_name = string(args_info.output_dir_arg) + "/" + strip_file_path(file_name);

  if (args_info.input_given)
    {
      input_file = string (args_info.input_arg);
      stripped_input_file = strip_file_path(input_file);
      open_input_file (input_file);
      // otherwise stdin already points to stdin
    }

  string source_ext;
  if (strcmp (args_info.output_format_arg, "cpp") == 0)
    {
      skel_factory = new SkelFactoryCpp;
      source_ext = "cc";
    }
  else if (strcmp (args_info.output_format_arg, "c") == 0)
    {
      skel_factory = new SkelFactoryC;
      source_ext = "c";
    }
  else if (strcmp (args_info.output_format_arg, "lua") == 0)
    {
      skel_factory = new SkelFactoryLua;
      source_ext = "lua";
    }
  else
    {
      string serr = "target language ";
      serr += args_info.output_format_arg;
      serr += " not recognized";
      gengen_error (serr);
    }

  if (args_info.separate_files_given && ! args_info.file_name_given)
    {
      gengen_error ("--separate-files requires --file-name option");
    }

  if (yyparse () == EXIT_FAILURE)
    return EXIT_FAILURE;

  StreamStruct streamstruct;

  ostringstream header_s;
  ostringstream source_s;
  if (args_info.file_name_given)
    {
      streamstruct.header_stream = &header_s;
      if (args_info.separate_files_given)
        streamstruct.source_stream = &source_s;
    }
  else
    streamstruct.header_stream = &cout;

  skel_struct = skel_factory->createSkelStruct
       (skel_items, gen_name, file_name, streamstruct,
         args_info.separate_files_given);

  skel_struct->generate ();

  if (args_info.file_name_given)
    {
      generate_code (header_s, create_output_filename(file_name));
      if (args_info.separate_files_given)
        {
          generate_code(source_s, create_output_filename(file_name, source_ext));
        }
    }

  return 0;
}

// check whether any change took place since the last generated file (if any exists)
void
generate_code(const ostringstream &stream, const string &file_name)
{
  const istream *previous = open_input_file_stream(file_name);
  bool generate = true;

  cerr << "generating " << file_name << "... ";

  const string &stream_buffer = stream.str();

  if ((! args_info.force_given) && previous && *previous)
    {
      ostringstream previous_s;
      previous_s << previous->rdbuf();
      if (previous_s.str() == stream_buffer)
        generate = false;
    }

  if (generate)
    {
      ostream &output_file = open_output_file(file_name);
      output_file << stream_buffer << flush;
      cerr << "done" << endl;
    }
  else
    cerr << "no change needed" << endl;
}

void
gengen_error(const string &s)
{
  cerr << "gengen: " << s << endl;
  exit (EXIT_FAILURE);
}
