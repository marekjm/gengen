//
// C++ Implementation: skelfactory
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "skelfactory.h"
#include "normaltext.h"
#include "varitem.h"

NormalText *
SkelFactory::createNormalText(const string &s)
{
  return new NormalText (s);
}

VarItem *
SkelFactory::createVarItem (const string &s, skelitem_type t,
                               SkelItemOptions opts)
{
  return new VarItem (s, t, opts);
}
