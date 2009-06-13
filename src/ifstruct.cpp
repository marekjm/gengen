//
// C++ Implementation: if_struct
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "ifstruct.h"
#include "expression.h"

IfStruct::IfStruct(Expression *e, const SkelItems *t, IfStruct *el) :
        SkelItemStruct ("", "_if_type"), exp (e), then_branch (t), else_branch (el)
{
}

IfStruct::~IfStruct()
{
  if (exp)
    delete exp;

  if (else_branch)
    delete else_branch;
}
