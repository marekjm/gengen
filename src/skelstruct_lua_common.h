
//
// C++ Interface: skelstruct_lua_common
//
// Description:
//
//
// Author: Raman Gopalan <ramangopalan@gmail.com>
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef SKELSTRUCT_LUA_COMMON_H
#define SKELSTRUCT_LUA_COMMON_H

#include "skelstruct.hpp"

#include "my_sstream.h"

class ExpressionGeneratorLua;

/**
A base class that contains shared methods for Lua related generation code

@author Raman Gopalan
*/
class SkelStruct_Lua_Common : public SkelStruct
{
  protected:
    /// the generator for expressions
    ExpressionGeneratorLua *expGen;

  public:
    SkelStruct_Lua_Common(SkelItems* items, const string& n, const string& file, StreamStruct& s, bool sep);
    virtual ~SkelStruct_Lua_Common();

    virtual void if_generation(const string &exp, const string &then_branch,
                             const string &else_branch, ostream &stream,
                             unsigned int indent);
    virtual const string field_prefix() { return "record."; }

    virtual void exp_generation( Expression *exp, ostream &stream );

    /**
     * This is the factory method used to create an ExpressionGenerator for Lua
     *
     * @return The created ExpressionGenerator
     */
    virtual ExpressionGeneratorLua *createExpGenLua(ostream &stream);
};

#endif // SKELSTRUCT_LUA_COMMON_H
