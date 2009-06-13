//
// C++ Interface: expressionchecker
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef EXPRESSIONCHECKER_H
#define EXPRESSIONCHECKER_H

#include "expressionvisitor.hpp"
#include "expressiontype.h"

#include <string>

/**
checks an expression (and its subexpression), e.g., performs type checking

	@author Lorenzo Bettini <http://www.lorenzobettini.it>
*/
class ExpressionChecker : public ExpressionVisitor
{
  protected:
    /// if not empty contains the error message
    std::string error;

public:
    ExpressionChecker();

    ~ExpressionChecker();

    virtual void visit(Expression *exp);
    virtual void visit(UnaryExpression *exp);
    virtual void visit(BinaryExpression *exp);

    const std::string &getError() const { return error; }
    void resetError() { error = ""; }
};

#endif
