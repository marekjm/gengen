//
// C++ Implementation: expressiongenerator_cpp
//
// Description: output C++ interpretation of expressions
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "expressiongenerator_cpp.h"

#include "unaryexpression.h"
#include "binaryexpression.h"
#include "expressionoperators.h"

#include <assert.h>

ExpressionGeneratorCpp::ExpressionGeneratorCpp(std::ostream &o)
  : out(&o)
{
  operatorMap[ANDOP] = "&&";
  operatorMap[OROP] = "||";
  operatorMap[NOTOP] = "!";
  operatorMap[LESSOP] = "<";
  operatorMap[GREATEROP] = ">";
  operatorMap[EQUALOP] = "==";
  operatorMap[NEQUALOP] = "!=";
  operatorMap[LESSEOP] = "<=";
  operatorMap[GREATEREOP] = "=>";
}


void ExpressionGeneratorCpp::visit(Expression *exp)
{
  *out << (exp->isConst() ? "" : prefix) << exp->getText();
}

void ExpressionGeneratorCpp::visit(UnaryExpression *exp)
{
  assert(operatorMap.find(exp->getOperator()) != operatorMap.end());
  
  *out << "( " << operatorMap[exp->getOperator()] << " ";
  ExpressionVisitor::visit(exp);
  *out << " )";
}

void ExpressionGeneratorCpp::visit(BinaryExpression *exp)
{
  assert(operatorMap.find(exp->getOperator()) != operatorMap.end());
  
  *out << "( ";
  visit_DB(exp->getLeftExpression());
  *out << " " << operatorMap[exp->getOperator()] << " ";
  visit_DB(exp->getRightExpression());
  *out << " )";
}
