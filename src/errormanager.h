//
// C++ Interface: errormanager
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef ERRORMANAGER_H
#define ERRORMANAGER_H

#include <string>

class WithTokenInfo;

void print_error(const std::string &s, int l = -1);
void print_error(const std::string &s, const WithTokenInfo &);
void print_error(const std::string &s, const WithTokenInfo *);
void exit_failure();

#endif // ERRORMANAGER_H
