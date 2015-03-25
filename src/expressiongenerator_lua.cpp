
//
// C++ Implementation: expressiongenerator_lua
//
// Description: output Lua interpretation of expressions
//
//
// Author: Raman Gopalan <ramangopalan@gmail.com>
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "expressiongenerator_lua.h"
#include "unaryexpression.h"
#include "binaryexpression.h"
#include "expressionoperators.h"

#include <assert.h>

ExpressionGeneratorLua::ExpressionGeneratorLua(std::ostream &o)
  : out(&o)
{
  operatorMap[ANDOP] = "and";
  operatorMap[OROP] = "or";
  operatorMap[NOTOP] = "not";
  operatorMap[LESSOP] = "<";
  operatorMap[GREATEROP] = ">";
  operatorMap[EQUALOP] = "==";
  operatorMap[NEQUALOP] = "~=";
  operatorMap[LESSEOP] = "<=";
  operatorMap[GREATEREOP] = ">=";
}

void ExpressionGeneratorLua::visit(Expression *exp)
{
  *out << (exp->isConst() ? "" : prefix) << exp->getText();
}

void ExpressionGeneratorLua::visit(UnaryExpression *exp)
{
  assert(operatorMap.find(exp->getOperator()) != operatorMap.end());

  *out << "( " << operatorMap[exp->getOperator()] << " ";
  ExpressionVisitor::visit(exp);
  *out << " )";
}

void ExpressionGeneratorLua::visit(BinaryExpression *exp)
{
  assert(operatorMap.find(exp->getOperator()) != operatorMap.end());

  *out << "( ";
  visit_DB(exp->getLeftExpression());
  *out << " " << operatorMap[exp->getOperator()] << " ";
  visit_DB(exp->getRightExpression());
  *out << " )";
}
