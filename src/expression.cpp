//
// C++ Implementation: expression
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "expression.h"

Expression::Expression(const string &e, ExpressionType type) :
  SkelItemStruct (e, type), isconst (false)
{
}
