//
//
// C++ Implementation: skelfactory_c
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2003
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "skelfactory_c.h"
#include "skelstruct_c.h"

SkelStruct *
SkelFactoryC::createSkelStruct (SkelItems *items,
                                const string &name, const string &file_name,
                                StreamStruct &s, bool sep_files)
{
  return new SkelStructC (items, name, file_name, s, sep_files);
}

