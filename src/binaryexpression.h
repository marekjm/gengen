//
// C++ Interface: binaryexpression
//
// Description: 
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include <expressionwithop.h>

/**
Represents a binary expression

	@author Lorenzo Bettini <http://www.lorenzobettini.it>
*/
// doublecpp: forward declarations, DO NOT MODIFY
class ExpressionVisitor; // file: expressionvisitor.h
class SkelItems; // file: skelitems.h
class SkelStruct; // file: skelstruct.h
// doublecpp: end, DO NOT MODIFY

class BinaryExpression : public ExpressionWithOp
{
  private:
    Expression *leftExpression, *rightExpression;
    
public:
    BinaryExpression(const string& e, const std::string& op, 
                     Expression *left, Expression *right, 
                     ExpressionType type = NOTYPE);

    ~BinaryExpression();

    Expression *getLeftExpression() const { return leftExpression; }
    Expression *getRightExpression() const { return rightExpression; }
// doublecpp: dispatch methods, DO NOT MODIFY
public:
virtual void dispatch_add_var_item_const(SkelItems *);
virtual void dispatch_analyze_item(SkelStruct *);
virtual void dispatch_visit(ExpressionVisitor *);
// doublecpp: end, DO NOT MODIFY
};

#endif
