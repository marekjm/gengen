//
// C++ Implementation: expressiongenerator_c
//
// Description: output C interpretation of expressions
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "expressiongenerator_c.h"

#include "binaryexpression.h"
#include "expressionoperators.h"

#include <assert.h>

ExpressionGeneratorC::ExpressionGeneratorC(std::ostream &o)
  : ExpressionGeneratorCpp(o)
{
}


void ExpressionGeneratorC::visit(BinaryExpression *exp)
{
  ExpressionOperator op = exp->getOperator();
  // since subexpression must already have the same type we check
  // only one subexpression's type
  ExpressionType subExpType =
      exp->getLeftExpression()->getExpressionType();
  
  if (subExpType != STRING_TYPE) {
    // it's just the same as C++
    ExpressionGeneratorCpp::visit(exp);
  } else {
    assert(operatorMap.find(exp->getOperator()) != operatorMap.end());
    assert(isRelativeOp(op) || isExactCompareOp(op));
    
    // now we assume that the two subexpressions are either string variables
    // or string constants and not complex expressions (of type string)
    
    Expression *leftExp = exp->getLeftExpression();
    Expression *rightExp = exp->getRightExpression();
    
    // first check that non-constants are not NULL
    *out << "( ";
    
    if (!leftExp->isConst()) // generate a non null test for left expression
      visit_DB(leftExp);
    if (!rightExp->isConst()) {
      if (!leftExp->isConst())
        *out << " && ";
      visit_DB(rightExp);
    }
    
    if (!leftExp->isConst() || !rightExp->isConst())
      *out << " && ";
    
    *out << "strcmp( ";
    visit_DB(leftExp);
    *out << ", ";
    visit_DB(rightExp);
    *out << " ) ";
    
    if (isEqualOp(op)) {
      *out << "== 0";
    } if (isNEqualOp(op)) {
      *out << "!= 0";
    } else {
      // relative op
      *out << operatorMap[exp->getOperator()] << " 0";
    }
    
    *out << " )";
  }
}
