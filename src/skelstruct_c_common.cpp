//
// C++ Implementation: skelstruct_c_common
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "skelstruct_c_common.h"
#include "ifgen_c.h"
#include "expressiongenerator_c.h"

using std::endl;

SkelStruct_C_Cpp_Common::SkelStruct_C_Cpp_Common(SkelItems* items, const string& n, const string& file, StreamStruct& s, bool sep): SkelStruct(items, n, file, s, sep), expGen (0)
{
}

SkelStruct_C_Cpp_Common::~SkelStruct_C_Cpp_Common()
{
  if (expGen && !is_copy)
    delete expGen;
}


void
SkelStruct_C_Cpp_Common::if_generation(const string &exp, const string &then_branch,
                             const string &else_branch, ostream &stream,
                             unsigned int indent)
{
  bool empty_else = (!else_branch.size());
  
  ifgen_c_gen_class ifgen;
  ifgen.set_exp (exp);
  ifgen.set_then_body (then_branch);
  ifgen.set_else_body (else_branch);
  ifgen.set_skipelse (empty_else);

  ifgen.generate_ifgen_c (stream, indent);

  stream << endl;
}

void
SkelStruct_C_Cpp_Common::exp_generation(Expression *exp, ostream &stream)
{
  if (!expGen) {
    expGen = createExpGen(stream);
    expGen->setPrefix( field_prefix() );
  } else {
    expGen->setStream( stream );
  }

  expGen->visit_DB( exp );
}
  
SkelStruct_C_Common::SkelStruct_C_Common(SkelItems* items, const string& n, const string& file, StreamStruct& s, bool sep):
  SkelStruct_C_Cpp_Common(items, n, file, s, sep)
{
}

ExpressionGeneratorCpp *SkelStruct_C_Common::createExpGen(ostream &stream)
{
  return new ExpressionGeneratorC(stream);
}
