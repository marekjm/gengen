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

#include "skelitemstruct.h"

SkelItemStruct::SkelItemStruct(const string &s, const skelitem_type &t,
                               SkelItemOptions opts) :
  text (s), item_type (t), item_options (opts)
{
}

void
SkelItemStruct::replace_char(char repl, const string &with)
{
  string::size_type it;

  it = text.find (repl);

  while (it != string::npos)
    {
      text.replace (it, 1, with);
      it = text.find (repl, it + with.size ());
    }
}

void
SkelItemStruct::output(ostream *stream)
{
  *stream << text;
}


bool
SkelItemStruct::isToBePreProcessed () const
{
  return true;
}

ostream &
operator<<(ostream &stream, const SkelItemStruct &item)
{
  stream << item.getText ();
  return stream;
}
