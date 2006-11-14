//
// C++ Implementation: stringutil
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "stringutil.h"

string
trim(const string &s)
{
   string::size_type pos, pos2;

   if ((pos = s.find_first_not_of("\n ")) == string::npos)
     pos = 0;

   if ((pos2 = s.find_last_not_of('\n')) == string::npos)
     pos2 = s.size();

   return s.substr(pos, (pos2-pos)+1);
}
