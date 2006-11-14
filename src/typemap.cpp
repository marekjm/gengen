//
// C++ Implementation: typemap
//
// Description: 
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "typemap.h"

TypeMap::TypeMap()
 : std::map<ExpressionType, std::string>()
{
  (*this)[NOTYPE] = "untyped";
  (*this)[METHOD_TYPE] = "method";
  (*this)[BOOL_TYPE] = "bool";
  (*this)[INT_TYPE] = "int";
  (*this)[STRING_TYPE] = "string";
}


TypeMap::~TypeMap()
{
}


