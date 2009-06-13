/*
 * Copyright (C) 2002 Lorenzo Bettini <http://www.lorenzobettini.it>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef SKELITEMSTRUCT_H
#define SKELITEMSTRUCT_H

#include <string>
#include <iostream>
#include <functional>

#include "skelitemtype.h"
#include "skelitemoptions.h"
#include "withtokeninfo.h"

using std::string;
using std::ostream;

// doublecpp: forward declarations, DO NOT MODIFY
class OstreamInfo; // file: skelstruct.h
class SkelItems; // file: skelitems.h
class SkelStruct; // file: skelstruct.h
// doublecpp: end, DO NOT MODIFY

class SkelItemStruct : public WithTokenInfo
{
 protected:
  string text;
  skelitem_type item_type;
  SkelItemOptions item_options;

 public:
  SkelItemStruct(const string &s, const skelitem_type &t = NOTYPE,
                 SkelItemOptions opts = SkelItemOptions ());

  virtual ~SkelItemStruct() {}

  const string &getText () const { return text; }
  const skelitem_type &getType () const { return item_type; }
  void setType(const skelitem_type &t) { item_type = t; }
  const SkelItemOptions &getOptions () const { return item_options; }
  void replace_char (char repl, const string &with);

  bool operator<(const SkelItemStruct &s) const { return text < s.text; }

  virtual void output(ostream *stream);
  virtual bool isToBePreProcessed () const;
// doublecpp: dispatch methods, DO NOT MODIFY
public:
virtual void dispatch_add_var_item_const(SkelItems *);
virtual void dispatch_analyze_item(SkelStruct *);
virtual void dispatch_pre_process(SkelStruct *, OstreamInfo * o);
// doublecpp: end, DO NOT MODIFY
};

struct SkelItem_less
{
  bool operator() (const SkelItemStruct *i1, const SkelItemStruct *i2) const
  { return *i1 < *i2; }
};

ostream &
operator<<(ostream &stream, const SkelItemStruct &item) ;

#endif // SKELITEMSTRUCT_H
