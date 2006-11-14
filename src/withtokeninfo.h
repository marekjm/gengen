/***************************************************************************
 *   Copyright (C) 2003 by Lorenzo Bettini                                 *
 *   www.lorenzobettini.it                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef WITHTOKENINFO_H
#define WITHTOKENINFO_H

// the basic structure that contains information about token position
// in the source file (e.g., the line number).

class WithTokenInfo
{
 protected:
  int first_line;

 public:
  WithTokenInfo(int l = -1) : first_line (l) {}
  WithTokenInfo(const WithTokenInfo &t) : first_line (t.first_line) {}

  int getLine() const { return first_line; }
  void setInfo(int l)
  {
    first_line = l;
  }
};

#endif // WITHTOKENINFO_H
