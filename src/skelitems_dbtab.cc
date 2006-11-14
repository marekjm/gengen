#include "unaryexpression.h"

#include "ifstruct.h"

#include "expression.h"

#include "binaryexpression.h"

#include "skelitemstruct.h"

#include "skelitems.hpp"

void
SkelItems::add_var_item_DB(const SkelItemStruct * item)
{
  (const_cast<SkelItemStruct *>(item))->dispatch_add_var_item_const(this);
}

void
BinaryExpression::dispatch_add_var_item_const(SkelItems *SkelItems_o)
{
  SkelItems_o->_forward_add_var_item((const BinaryExpression *)(this));
}

void
Expression::dispatch_add_var_item_const(SkelItems *SkelItems_o)
{
  SkelItems_o->_forward_add_var_item((const Expression *)(this));
}

void
IfStruct::dispatch_add_var_item_const(SkelItems *SkelItems_o)
{
  SkelItems_o->_forward_add_var_item((const IfStruct *)(this));
}

void
SkelItemStruct::dispatch_add_var_item_const(SkelItems *SkelItems_o)
{
  SkelItems_o->_forward_add_var_item((const SkelItemStruct *)(this));
}

void
UnaryExpression::dispatch_add_var_item_const(SkelItems *SkelItems_o)
{
  SkelItems_o->_forward_add_var_item((const UnaryExpression *)(this));
}

