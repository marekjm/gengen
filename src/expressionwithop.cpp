//
// C++ Implementation: expressionwithop
//
// Description: 
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "expressionwithop.h"

ExpressionWithOp::ExpressionWithOp(const string &e, const std::string &op, ExpressionType type)
  : Expression(e, type), oper (op)
{
}


ExpressionWithOp::~ExpressionWithOp()
{
}


