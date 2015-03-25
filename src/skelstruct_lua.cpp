
//
//
// C++ Implementation: skelstruct_lua
//
// Description:
//
//
// Author: Raman Gopalan <ramangopalan@gmail.com>
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "skelstruct_lua.h"
#include "gengen_globals.h"
#include "gengen_cmdline_options.h"
#include "extern_function_lua.h"
#include "skelstruct_strcnt_lua.h"
#include "my_sstream.h"
#include "callextfun_lua.h"
#include "skelstruct_luastring.h"
#include "genstringfun_lua.h"
#include "lua_convert.h"
#include "outputluavar.h"
#include "streamstruct.h"
#include "utils.h"
#include "fileutil.h"

#define struct_suffix "_gen_table"

using std::endl;

SkelStructLua::SkelStructLua(SkelItems *items,
                             const string &name, const string &file_name,
                             StreamStruct &s, bool sep_files) :
  SkelStruct_Lua_Common (items, name, file_name, s, sep_files), num_of_methods (-1),
  num_of_normal_strings (-1)
{
}

SkelStructLua::~SkelStructLua()
{
}

void
SkelStructLua::generate()
{
  if (num_of_methods < 0)
    analyze_items ();

  string struct_name (name + struct_suffix);
  string headername_include = struct_name;

  Utils::toUpper(headername_include);

  lua_header_gen_class::set_structname (struct_name);
  initstructfun_lua_gen_class::set_structname (struct_name);

  string author = "by " AUTHOR " " EMAIL;
  string other_comments =  HOMEPAGE;

  genfunction_lua_gen_class::set_genname (name);
  strcntfunction_lua_gen_class::set_genname (name);
  genstrfunction_lua_gen_class::set_genname (name);

  lua_header_gen_class::set_package (PACKAGE);
  if (! no_gen_version)
    lua_header_gen_class::set_version (VERSION);
  lua_header_gen_class::set_author (author);
  lua_header_gen_class::set_othercomments (other_comments);
  lua_source_gen_class::set_package (PACKAGE);
  if (! no_gen_version)
    lua_source_gen_class::set_version (VERSION);
  lua_source_gen_class::set_author (author);
  lua_source_gen_class::set_othercomments (other_comments);

  // make sure to strip possible path
  set_headerfile (strip_file_path(file_name));

  generate_lua_header (*streamstruct.header_stream);

  streamstruct.header_stream->flush ();
}

void
SkelStructLua::generate_fields(ostream &stream, unsigned int indent)
{
  VarSetIterator it, end_it;
  const VarSet &var_set = skel_struct->getVarSet();
  string indent_string (indent, ' ');
  skelitem_type item_type;

  for (it = var_set.begin (); it != var_set.end (); ++it)
    {
      item_type = (*it)->getType ();
      stream << indent_string;
      stream << **it << ",\n";
    }
}

void
SkelStructLua::generate_genparameters(ostream &stream, unsigned int indent)
{
  VarSetIterator it;
  const VarSet &var_set = skel_struct->getVarSet();
  skelitem_type item_type;

  for (it = var_set.begin (); it != var_set.end (); ++it)
    {
      item_type = (*it)->getType ();
      stream << ", " << **it;
    }
}

void
SkelStructLua::generate_genstring(ostream &stream, unsigned int indent)
{
  if (sep_files)
    return;

  generate_genstringfun( stream, indent);
}

void
SkelStructLua::generate_genstringfun(ostream &stream, unsigned int indent)
{
  if (! has_expand_strings ())
    return;

  genstringfun_lua_gen_class genstring;
  genstring.generate_genstringfun_lua (stream, indent);
}

void
SkelStructLua::generate_genconvfun(ostream &stream, unsigned int indent)
{
  if (! has_ints_to_generate() && ! has_booleans_to_generate())
    return;

  lua_convert_gen_class gen;
  gen.set_hasints(has_ints_to_generate());
  gen.set_hasbools(has_booleans_to_generate());
  gen.generate_lua_convert (stream, indent);
}

void
SkelStructLua::generate_genconv(ostream &stream, unsigned int indent)
{
  if (sep_files)
    return;

  generate_genconvfun (stream, indent);
}

void
SkelStructLua::generate_genfieldinit(ostream &stream, unsigned int indent)
{
  VarSetIterator it;
  const VarSet &var_set = skel_struct->getVarSet();
  string indent_string (indent, ' ');
  skelitem_type item_type;

  for (it = var_set.begin (); it != var_set.end (); ++it)
    {
      item_type = (*it)->getType ();
      if (isVariableType( item_type ))
        {
          stream << indent_string;
          stream << "record." << **it << " = nil\n";
        }
    }
}

void
SkelStructLua::generate_assignfields(ostream &stream, unsigned int indent)
{
  VarSetIterator it;
  const VarSet &var_set = skel_struct->getVarSet();
  string indent_string (indent, ' ');
  skelitem_type item_type;

  stream << endl;

  for (it = var_set.begin (); it != var_set.end (); ++it)
    {
      item_type = (*it)->getType ();
      if (isVariableType( item_type ))
        {
          stream << indent_string;
          stream << "record." << **it << " = " << **it << "\n";
        }
    }
}

void
SkelStructLua::generate_strgeninstructions(ostream &stream, unsigned int indent)
{
  SkelStructLuaString luastring_gen (*this);
  luastring_gen.start_generation (stream, indent);
}

void
SkelStructLua::generate_funbody(ostream &stream, unsigned int indent)
{
  if (sep_files)
    {
      generate_lua_source (*streamstruct.source_stream, 0);

      streamstruct.source_stream->flush ();
    }
  else
    {
      generate_genfunction_lua (stream, 0);
      generate_genstrfunction_lua (stream, 0);
      generate_strcntfunction_lua (stream, 0);
      generate_initstructfun_lua (stream, 0);
    }
}

void
SkelStructLua::generate_genfunbody(ostream &stream, unsigned int indent)
{
  generate_genfunction_lua (stream, 0);
  generate_genstrfunction_lua (stream, 0);
  generate_strcntfunction_lua (stream, 0);
  generate_initstructfun_lua (stream, 0);
}

void
SkelStructLua::generate_externfunctions(ostream &stream, unsigned int indent)
{
  VarSetIterator it;
  const VarSet &var_set = skel_struct->getVarSet();
  skelitem_type item_type;
  extern_function_lua_gen_class extfun_gen_lua;

  for (it = var_set.begin (); it != var_set.end (); ++it)
    {
      item_type = (*it)->getType ();

      if (item_type == METHOD_TYPE)
        {
          extfun_gen_lua.set_name ((*it)->getText ());
          extfun_gen_lua.generate_extern_function_lua (stream, indent);

          stream << endl;
          stream << endl;
        }
    }
}

void
SkelStructLua::generate_geninstructions(ostream &stream, unsigned int indent)
{
  gen_generate_instructions (stream, indent);
}

void
SkelStructLua::generate_compleninstr(ostream &stream, unsigned int indent)
{
  SkelStructStrCntLua strcnt (*this);

  int const_len = strcnt.compute_length (stream, indent);

  ostringstream const_len_s;
  const_len_s << const_len;

  set_constlen (const_len_s.str ());
}

void
SkelStructLua::call_external_function(ostream &stream, const string &name,
                                      unsigned int indent)
{
  callextfun_lua_gen_class callext;
  callext.set_name (name);
  callext.generate_callextfun_lua (stream, indent);
  stream << endl;
}

void
SkelStructLua::std_generation(ostream &stream, const string &s)
{
  stream << "io.write(" << s << ")\n";
}

void
SkelStructLua::variable_generation(ostream &stream, const string &name,
                                   const skelitem_type &type,
                                   unsigned int indent)
{
  ostringstream luavar;

  if (canBeString( type ) || expand_tabs) {
    outputluavar_gen_class luavar_gen (name);
    luavar_gen.generate_outputluavar (luavar);
  } else {
    luavar << field_prefix() << name;
  }

  // instead of relying on the convert functions, since printf
  // can handle integers, we use this feature directly
  if (expand_tabs)
    stream << "generate_string (" + luavar.str () +
      ", stream, indent + string.len (indent_str))\n";
  else
    stream << "io.write(" << luavar.str () << ")\n";
}

