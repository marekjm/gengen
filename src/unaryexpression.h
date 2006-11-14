//
// C++ Interface: unaryexpression
//
// Description: 
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include "expressionwithop.h"

/**
Represents an unary expression

	@author Lorenzo Bettini <http://www.lorenzobettini.it>
*/
// doublecpp: forward declarations, DO NOT MODIFY
class ExpressionVisitor; // file: expressionvisitor.h
class SkelItems; // file: skelitems.h
class SkelStruct; // file: skelstruct.h
// doublecpp: end, DO NOT MODIFY

class UnaryExpression : public ExpressionWithOp
{
protected:
  Expression *subExpression;
  
public:
    UnaryExpression(const string& e, const std::string& op, 
                    Expression *subExp, ExpressionType type = NOTYPE);

    ~UnaryExpression();
    
    Expression *getSubExpression() const { return subExpression; }
// doublecpp: dispatch methods, DO NOT MODIFY
public:
virtual void dispatch_add_var_item_const(SkelItems *);
virtual void dispatch_analyze_item(SkelStruct *);
virtual void dispatch_visit(ExpressionVisitor *);
// doublecpp: end, DO NOT MODIFY
};

#endif
