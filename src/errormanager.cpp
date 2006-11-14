//
// C++ Implementation: errormanager
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <iostream>
#include <stdlib.h>

#include "errormanager.h"
#include "sourcename.h"
#include "withtokeninfo.h"
#include "gengen_cmdline_options.h"

using namespace std;

void
print_error(const std::string &s, int line)
{
  cerr << stripped_input_file << ":";
  if (line > 0)
    cerr << line;
  
  std::string::size_type newline = s.find("\n");
  cerr << ": " << 
      (newline != std::string::npos ? s.substr(0, newline) : s) << std::endl;
  
  if (newline == std::string::npos)
    return;
  
  print_error(s.substr(newline+1), line);
}

void
print_error(const std::string &s, const WithTokenInfo &w)
{
  print_error(s, w.getLine());
}

void
print_error(const std::string &s, const WithTokenInfo *w)
{
  print_error(s, *w);
}

void
exit_failure()
{
  if (! test_mode)
    exit (EXIT_FAILURE);

  exit (EXIT_SUCCESS);
}
