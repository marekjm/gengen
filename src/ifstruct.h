//
// C++ Interface: if_struct
//
// Description: 
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef IF_STRUCT_H
#define IF_STRUCT_H

#include "skelitemstruct.h"

class Expression;
class SkelItems;

// doublecpp: forward declarations, DO NOT MODIFY
class OstreamInfo; // file: skelstruct.h
class SkelItems; // file: skelitems.h
class SkelStruct; // file: skelstruct.h
// doublecpp: end, DO NOT MODIFY

class IfStruct : public SkelItemStruct
{
protected:
  Expression *exp;
  const SkelItems *then_branch;
  IfStruct *else_branch;

public:
  IfStruct(Expression *e = 0, const SkelItems *t = 0, IfStruct *el = 0);
  virtual ~IfStruct();

  IfStruct *getElseBranch() const { return else_branch; }
  Expression *getExpression() const { return exp; }
  const SkelItems *getThenBranch() const { return then_branch; }
// doublecpp: dispatch methods, DO NOT MODIFY
public:
virtual void dispatch_add_var_item_const(SkelItems *);
virtual void dispatch_analyze_item(SkelStruct *);
virtual void dispatch_pre_process(SkelStruct *, OstreamInfo * o);
// doublecpp: end, DO NOT MODIFY
};

#endif // IF_STRUCT_H
