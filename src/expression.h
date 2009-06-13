//
// C++ Interface: expression
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "skelitemstruct.h"

#include "expressiontype.h"

// doublecpp: forward declarations, DO NOT MODIFY
class ExpressionVisitor; // file: expressionvisitor.h
class SkelItems; // file: skelitems.h
class SkelStruct; // file: skelstruct.h
// doublecpp: end, DO NOT MODIFY

class Expression : public SkelItemStruct
{
  private:
    bool isconst; /// whether this is a constant expression

public:
  Expression(const string &e, ExpressionType type = BOOL_TYPE);

  const ExpressionType &getExpressionType() const { return getType(); }
  void setExpressionType(ExpressionType t) { setType( t ); }

  bool isConst() const { return isconst; }
  void setIsConst(bool i) { isconst = i; }

// doublecpp: dispatch methods, DO NOT MODIFY
public:
virtual void dispatch_add_var_item_const(SkelItems *);
virtual void dispatch_analyze_item(SkelStruct *);
virtual void dispatch_visit(ExpressionVisitor *);
// doublecpp: end, DO NOT MODIFY
};

#endif // EXPRESSION_H
