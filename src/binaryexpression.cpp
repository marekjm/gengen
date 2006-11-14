//
// C++ Implementation: binaryexpression
//
// Description: 
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "binaryexpression.h"

BinaryExpression::BinaryExpression(const string& e, const std::string& op, 
          Expression *left, Expression *right, ExpressionType type): 
  ExpressionWithOp(e, op, type), leftExpression(left), rightExpression(right)
{
  // we get line info from the left subexpression
  if (leftExpression)
    setInfo( leftExpression->getLine() );
}


BinaryExpression::~BinaryExpression()
{
  if (leftExpression)
    delete leftExpression;
  
  if (rightExpression)
    delete rightExpression;
}


