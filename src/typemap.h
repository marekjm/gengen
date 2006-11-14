//
// C++ Interface: typemap
//
// Description: 
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef TYPEMAP_H
#define TYPEMAP_H

#include <map>
#include <string>
#include "expressiontype.h"

typedef std::map<ExpressionType, std::string> TypeMapBase;

/**
Maps type identifiers to actual string representation of types

	@author Lorenzo Bettini <http://www.lorenzobettini.it>
*/
class TypeMap : public TypeMapBase
{
public:
    TypeMap();

    ~TypeMap();

};

#endif
