//
// C++ Interface: expressionwithop
//
// Description: 
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef EXPRESSIONWITHOP_H
#define EXPRESSIONWITHOP_H

#include <expression.h>

/**
a generic class for expression containing an operator

	@author Lorenzo Bettini <http://www.lorenzobettini.it>
*/
typedef std::string ExpressionOperator;

class ExpressionWithOp : public Expression
{
  protected:
    ExpressionOperator oper;
public:
  ExpressionWithOp(const string &e, const std::string &op, ExpressionType type = BOOL_TYPE);

  ~ExpressionWithOp();
  
  const ExpressionOperator &getOperator() const { return oper; }
};

#endif
