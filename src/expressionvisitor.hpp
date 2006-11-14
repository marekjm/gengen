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
// doublecpp: forward declarations, DO NOT MODIFY
class BinaryExpression; // file: binaryexpression.h
class Expression; // file: expression.h
class UnaryExpression; // file: unaryexpression.h
// doublecpp: end, DO NOT MODIFY

#line 20 "expressionvisitor.h"
class ExpressionVisitor
{
public:
    ExpressionVisitor();

    virtual ~ExpressionVisitor();

// doublecpp: method branches, DO NOT MODIFY
#line 27 "expressionvisitor.h"
virtual void visit(Expression * exp);
#line 28 "expressionvisitor.h"
virtual void visit(UnaryExpression * exp);
#line 29 "expressionvisitor.h"
virtual void visit(BinaryExpression * exp);
virtual void visit_DB(Expression * exp);
#line 29 "expressionvisitor.h"
// doublecpp: end, DO NOT MODIFY

};

#endif
