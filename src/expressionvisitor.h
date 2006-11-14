//
// C++ Interface: expressionvisitor
//
// Description: 
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef EXPRESSIONVISITOR_H
#define EXPRESSIONVISITOR_H

/**
generic visitor that visits an expression (and all it subexpressions)

	@author Lorenzo Bettini <http://www.lorenzobettini.it>
*/
class ExpressionVisitor{
public:
    ExpressionVisitor();

    virtual ~ExpressionVisitor();

    branches visit
    void (Expression *exp);
    void (UnaryExpression *exp);
    void (BinaryExpression *exp);
    endbranches
};

#endif
