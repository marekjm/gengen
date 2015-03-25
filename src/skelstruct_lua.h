
//
//
// C++ Interface: skelstruct_lua
//
// Description:
//
//
// Author: Raman Gopalan <ramangopalan@gmail.com>
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef SKELSTRUCT_LUA_H
#define SKELSTRUCT_LUA_H

#include "skelstruct_lua_common.h"
#include "lua_header.h"
#include "genfunction_lua.h"
#include "lua_source.h"
#include "strcntfunction_lua.h"
#include "initstructfun_lua.h"
#include "genstrfunction_lua.h"

/**
 * Class for generation of Lua code
 */
class SkelStructLua : public SkelStruct_Lua_Common, public lua_header_gen_class,
                      public genfunction_lua_gen_class, public lua_source_gen_class,
                      public strcntfunction_lua_gen_class, public initstructfun_lua_gen_class,
                      public genstrfunction_lua_gen_class
{
 protected:
  int num_of_methods;
  int num_of_normal_strings;

 public:
  // redefined from c_header_gen_class
  virtual void generate_fields(ostream &stream, unsigned int indent);
  virtual void generate_funbody(ostream &stream, unsigned int indent);
  virtual void generate_externfunctions(ostream &stream, unsigned int indent);
  virtual void generate_genparameters(ostream &stream, unsigned int indent);
  virtual void generate_genstring(ostream &stream, unsigned int indent);
  virtual void generate_genconv(ostream &stream, unsigned int indent);

  // redefined from genfunction_gen_class
  virtual void generate_geninstructions(ostream &stream, unsigned int indent);
  virtual void generate_assignfields(ostream &stream, unsigned int indent);

  // redefined from c_source_gen_class
  virtual void generate_genfunbody(ostream &stream, unsigned int indent);
  virtual void generate_genstringfun(ostream &stream, unsigned int indent);
  virtual void generate_genconvfun(ostream &stream, unsigned int indent);

  // redefined from strcntfunction_gen_class
  virtual void generate_compleninstr(ostream &stream, unsigned int indent);

  // redefined from initstructfun_gen_class
  virtual void generate_genfieldinit(ostream &stream, unsigned int indent);

  // redefined from genstrfunction_gen_class
  virtual void generate_strgeninstructions(ostream &stream, unsigned int indent);

  // redefined from SkelStruct
  virtual void call_external_function(ostream &stream, const string &name,
                                      unsigned int indent);
  virtual void std_generation(ostream &stream, const string &s);
  virtual void variable_generation(ostream &stream, const string &name,
                                   const skelitem_type &t,
                                   unsigned int indent);

 public:
  SkelStructLua (SkelItems *items,
                 const string &n, const string &file_name, StreamStruct &s,
                 bool sep_files);
  virtual ~SkelStructLua();

  virtual void generate();
};

#endif // SKELSTRUCT_LUA_H
