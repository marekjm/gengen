
//
//
// C++ Implementation: skelfactory_lua
//
// Description:
//
//
// Author: Raman Gopalan <ramangopalan@gmail.com>
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "skelfactory_lua.h"
#include "skelstruct_lua.h"

SkelStruct *
SkelFactoryLua::createSkelStruct (SkelItems *items,
				  const string &name,
				  const string &file_name,
				  StreamStruct &s,
				  bool sep_files)
{
  return new SkelStructLua (items, name, file_name, s, sep_files);
}
