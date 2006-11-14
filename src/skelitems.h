//
// C++ Interface: skelitems
//
// Description: 
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef SKELITEMS_H
#define SKELITEMS_H

#include <map>
#include <deque>
#include <set>

#include "skelitemstruct.h"

using std::set;
using std::deque;
using std::map;

typedef set<const SkelItemStruct *, SkelItem_less> VarSet;
typedef VarSet::const_iterator VarSetIterator;

class SkelItems : public deque<SkelItemStruct *>
{
 protected:
  typedef map<string, int> var_counter_type;
  typedef deque<SkelItemStruct *> SkelItemsBase;

  VarSet var_set;
  var_counter_type var_occur_cnt;

  bool is_copy;
  
  branches add_var_item
  void (const SkelItemStruct *item);
  void (const IfStruct *ifstruct);
  void (const Expression *exp);
  void (const UnaryExpression *exp);
  void (const BinaryExpression *exp);
  endbranches
  
  /**
   * Update the set of variables and their occurrence number.
   * If the item is a variable used as an expression (i.e., used in an if), 
   * its occurrence count is not updated
   * @param item The variable
   * @param isExp Whether this variable occurrence is inside an
   * expression (i.e., an if)
   */
  void update_var_set(const SkelItemStruct *item, bool isExp = false);
  /**
   * Update the set of variables and their occurrence number found in
   * the item collection.
   * @param items The item collection to analyze
   */
  void update_var_set(const SkelItems *items);

 public:
  SkelItems();
  SkelItems(const SkelItems &);
  virtual ~SkelItems();

  typedef const_iterator iterator;

  void add_item(SkelItemStruct *item);
  const VarSet &getVarSet() const { return var_set; }
  int getVarOccurCnt(const string &name) { return var_occur_cnt[name]; }
};

#endif // SKELITEMS_H
