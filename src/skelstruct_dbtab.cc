#include "varitem.h"

#include "unaryexpression.h"

#include "ifstruct.h"

#include "expression.h"

#include "binaryexpression.h"

#include "skelitemstruct.h"

#include "skelstruct.hpp"

void
SkelStruct::analyze_item_DB(SkelItemStruct * v)
{
  v->dispatch_analyze_item(this);
}

void
SkelStruct::pre_process_DB(SkelItemStruct * s, OstreamInfo * o)
{
  s->dispatch_pre_process(this, o);
}

void
BinaryExpression::dispatch_analyze_item(SkelStruct *SkelStruct_o)
{
  SkelStruct_o->_forward_analyze_item(this);
}

void
Expression::dispatch_analyze_item(SkelStruct *SkelStruct_o)
{
  SkelStruct_o->_forward_analyze_item(this);
}

void
IfStruct::dispatch_analyze_item(SkelStruct *SkelStruct_o)
{
  SkelStruct_o->_forward_analyze_item(this);
}

void
IfStruct::dispatch_pre_process(SkelStruct *SkelStruct_o, OstreamInfo * o)
{
  SkelStruct_o->_forward_pre_process(this, o);
}

void
SkelItemStruct::dispatch_analyze_item(SkelStruct *SkelStruct_o)
{
  SkelStruct_o->_forward_analyze_item(this);
}

void
SkelItemStruct::dispatch_pre_process(SkelStruct *SkelStruct_o, OstreamInfo * o)
{
  SkelStruct_o->_forward_pre_process(this, o);
}

void
UnaryExpression::dispatch_analyze_item(SkelStruct *SkelStruct_o)
{
  SkelStruct_o->_forward_analyze_item(this);
}

void
VarItem::dispatch_analyze_item(SkelStruct *SkelStruct_o)
{
  SkelStruct_o->_forward_analyze_item(this);
}

void
VarItem::dispatch_pre_process(SkelStruct *SkelStruct_o, OstreamInfo * o)
{
  SkelStruct_o->_forward_pre_process(this, o);
}

