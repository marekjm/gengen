
//
// C++ Implementation: skelstruct_lua_common
//
// Description:
//
//
// Author: Raman Gopalan <ramangopalan@gmail.com>
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "skelstruct_lua_common.h"
#include "ifgen_lua.h"
#include "expressiongenerator_lua.h"

using std::endl;

SkelStruct_Lua_Common::SkelStruct_Lua_Common(SkelItems* items, const string& n, const string& file, StreamStruct& s, bool sep): SkelStruct(items, n, file, s, sep), expGen (0)
{
}

SkelStruct_Lua_Common::~SkelStruct_Lua_Common()
{
  if (expGen && !is_copy)
    delete expGen;
}

void
SkelStruct_Lua_Common::if_generation(const string &exp, const string &then_branch,
                             const string &else_branch, ostream &stream,
                             unsigned int indent)
{
  bool empty_else = (!else_branch.size());
  
  ifgen_lua_gen_class ifgen;
  ifgen.set_exp (exp);
  ifgen.set_then_body (then_branch);
  ifgen.set_else_body (else_branch);
  ifgen.set_skipelse (empty_else);

  ifgen.generate_ifgen_lua (stream, indent);

  stream << endl;
}


void
SkelStruct_Lua_Common::exp_generation(Expression *exp, ostream &stream)
{
  if (!expGen) {
    expGen = createExpGenLua(stream);
    expGen->setPrefix( field_prefix() );
  } else {
    expGen->setStream( stream );
  }

  expGen->visit_DB( exp );
}

ExpressionGeneratorLua *SkelStruct_Lua_Common::createExpGenLua(ostream &stream)
{
  return new ExpressionGeneratorLua(stream);
}
