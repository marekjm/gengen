//
// C++ Implementation: expressionchecker
//
// Description: 
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "expressionchecker.h"

#include "unaryexpression.h"
#include "binaryexpression.h"
#include "expressionoperators.h"

/*
  performs a visit on a subexpression and if there's an error interrupts the visit
*/
#define visit_and_check(exp) \
   visit_DB(exp); \
   if (error.size()) \
     return;

#define set_error(err) \
    error = err; \
    return;

#define not_boolean(exp) \
    set_error(exp + " is not a boolean expression");

TypeMap ExpressionChecker::typeMap;

ExpressionChecker::ExpressionChecker()
 : ExpressionVisitor()
{
}

ExpressionChecker::~ExpressionChecker()
{
}

void ExpressionChecker::visit( Expression *exp )
{
  if (exp->getExpressionType() == NOTYPE)
    error = "untyped expression " + exp->getText();
}

void ExpressionChecker::visit( UnaryExpression *exp )
{
  Expression *subExpression = exp->getSubExpression();
  
  visit_and_check(subExpression);
  
  ExpressionOperator op = exp->getOperator();
  ExpressionType type = subExpression->getExpressionType();
  
  if (isNotOp(op) && type != BOOL_TYPE) {
    not_boolean(subExpression->getText());
  }
  
  // we get the same type of the subexpression
  exp->setExpressionType( type );
}

void ExpressionChecker::visit( BinaryExpression *exp )
{
  Expression *left = exp->getLeftExpression();
  Expression *right = exp->getRightExpression();
  
  visit_and_check(left);
  visit_and_check(right);
  
  ExpressionType leftType = left->getExpressionType();
  ExpressionType rightType = right->getExpressionType();

  if (leftType != rightType) {
    error = left->getText() + " and " + right->getText() + 
        " must have the same type\n" +
        left->getText() + " has type " + typeMap[leftType] + ", " +
        right->getText() + " has type " + typeMap[rightType];
    return;
  }
  
  ExpressionOperator op = exp->getOperator();
  
  // by now we already checked that subexpressions have the same type
  if (isBooleanOp(op)) {
    if (leftType != BOOL_TYPE) {
      not_boolean(left->getText());
    }
    exp->setExpressionType( BOOL_TYPE );
  } else if (isRelativeOp(op)) {
    if (leftType == BOOL_TYPE) {
      set_error(op + " cannot act on boolean expressions " + left->getText() + 
               " and " + right->getText());
    }
    exp->setExpressionType( BOOL_TYPE );
  } else if (isExactCompareOp(op)) {
    // equal works for any type and we have already checked
    // that the two subexpressions have the same type
    exp->setExpressionType( BOOL_TYPE );
  }
  
  // otherwise the type is still no type
}
