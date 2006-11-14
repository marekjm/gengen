//
// C++ Implementation: skelitems
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "skelitems.hpp"
#include "ifstruct.h"
#include "unaryexpression.h"
#include "binaryexpression.h"

SkelItems::SkelItems() : is_copy (false)
{
}

SkelItems::SkelItems(const SkelItems &s) :
        SkelItemsBase (s),
        var_set (s.var_set),
        var_occur_cnt (s.var_occur_cnt),
        is_copy (true)
{
}

SkelItems::~SkelItems()
{
  if (is_copy)
    return;

  iterator it;

  for (it = begin (); it != end (); ++it)
    delete *it;
}

void
SkelItems::add_item(SkelItemStruct *item)
{
  push_back (item);

  if (item->isToBePreProcessed ())
    {
      add_var_item_DB(item);
    }
}

void
SkelItems::update_var_set(const SkelItemStruct *item, bool isExp)
{
  if (!item)
    return;

  if (var_set.find (item) == var_set.end ())
    {
      var_set.insert (item);
      var_occur_cnt[item->getText()] = 0;
    }
    
    if (!isExp) // update the count only if it's not in an expression
      var_occur_cnt[item->getText()]++;
}

void
SkelItems::update_var_set(const SkelItems *items)
{
  if (!items)
    return;

  for (iterator it = items->begin(); it != items->end(); ++it)
    if ((*it)->isToBePreProcessed())
      add_var_item_DB (*it);
}


void
SkelItems::add_var_item(const SkelItemStruct *item)
{
  update_var_set(item);
}

void
SkelItems::add_var_item(const Expression *exp)
{
  if (exp->isConst())
    return; // no variable to update
  
  update_var_set(exp, true);
}

void
SkelItems::add_var_item(const UnaryExpression *exp)
{
  add_var_item_DB(exp->getSubExpression());
}

void
SkelItems::add_var_item(const BinaryExpression *exp)
{
  add_var_item_DB(exp->getLeftExpression());
  add_var_item_DB(exp->getRightExpression());
}

void
SkelItems::add_var_item(const IfStruct *ifstruct)
{
  if (! ifstruct) // case of an empty else_branch
    return;
  
  Expression *exp = ifstruct->getExpression();
  if (exp)
    add_var_item_DB(exp);
  // remember: exp can be null if we're visiting an else branch
  // which corresponds to an if with empty expression
  
  update_var_set(ifstruct->getThenBranch());
  add_var_item(ifstruct->getElseBranch());
}
