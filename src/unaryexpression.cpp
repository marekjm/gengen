//
// C++ Implementation: unaryexpression
//
// Description: 
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "unaryexpression.h"

UnaryExpression::UnaryExpression(const string& e, const std::string& op, 
    Expression *subExp, ExpressionType type) : 
ExpressionWithOp(e, op, type), subExpression (subExp)
{
  if (subExpression)
    setInfo( subExpression->getLine() );
}


UnaryExpression::~UnaryExpression()
{
  if (subExpression)
    delete subExpression;
}


