//
//
// C++ Interface: skelfactory_c
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2003
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef SKELFACTORY_C_H
#define SKELFACTORY_C_H

// implementation of pattern "Abstract Factory"
// this generates C code

#include "skelfactory.h"

class SkelFactoryC : public SkelFactory
{
 public:
  virtual SkelStruct *createSkelStruct (SkelItems *items,
                                        const string &name,
                                        const string &file_name, StreamStruct &,
                                        bool sep_files);
};

#endif // SKELFACTORY_C_H
