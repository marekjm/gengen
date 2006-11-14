//
// C++ Implementation: expressionvisitor
//
// Description: 
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "expressionvisitor.hpp"

#include "unaryexpression.h"
#include "binaryexpression.h"

ExpressionVisitor::ExpressionVisitor()
{
}


ExpressionVisitor::~ExpressionVisitor()
{
}

void ExpressionVisitor::visit(Expression *exp)
{
}

void ExpressionVisitor::visit(UnaryExpression *exp)
{
  visit_DB(exp->getSubExpression());
}

void ExpressionVisitor::visit(BinaryExpression *exp)
{
  visit_DB(exp->getLeftExpression());
  visit_DB(exp->getRightExpression());
}
