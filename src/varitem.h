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

#ifndef VARITEM_H
#define VARITEM_H

#include "skelitemstruct.h"

// doublecpp: forward declarations, DO NOT MODIFY
class OstreamInfo; // file: skelstruct.h
class SkelStruct; // file: skelstruct.h
// doublecpp: end, DO NOT MODIFY

class VarItem : public SkelItemStruct
{
 public:
  VarItem(const string &s, const skelitem_type &t, SkelItemOptions opts);
// doublecpp: dispatch methods, DO NOT MODIFY
public:
virtual void dispatch_analyze_item(SkelStruct *);
virtual void dispatch_pre_process(SkelStruct *, OstreamInfo * o);
// doublecpp: end, DO NOT MODIFY
};

#endif // VARITEM_H
