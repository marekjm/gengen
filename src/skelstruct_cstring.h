//
// C++ Interface: skelstruct_cstring
//
// Description: generate into a C string instead of into a file
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2003
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef SKELSTRUCT_CSTRING_H
#define SKELSTRUCT_CSTRING_H

#include "skelstruct_c_common.h"

class SkelStructCString : public SkelStruct_C_Common
{
 public:
  // redefined from SkelStruct
  virtual void call_external_function(ostream &stream, const string &name,
                                      unsigned int indent);
  virtual void std_generation(ostream &stream, const string &s);
  virtual void variable_generation(ostream &stream, const string &name,
                                   skelitem_type t,
                                   unsigned int indent);
  
 public:
  SkelStructCString (const SkelStruct_C_Common &s);

  void start_generation (ostream &stream, unsigned int indent);
};

#endif // SKELSTRUCT_CSTRING_H
