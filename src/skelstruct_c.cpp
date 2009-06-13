//
//
// C++ Implementation: skelstruct_c
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2003
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "skelstruct_c.h"
#include "gengen_globals.h"
#include "gengen_cmdline_options.h"
#include "extern_function.h"
#include "skelstruct_strcnt.h"
#include "my_sstream.h"
#include "callextfun.h"
#include "skelstruct_cstring.h"
#include "genstringfun.h"
#include "c_convert.h"
#include "outputcvar.h"
#include "streamstruct.h"
#include "utils.h"

#define struct_suffix "_gen_struct"

using std::endl;

SkelStructC::SkelStructC(SkelItems *items,
                         const string &name, const string &file_name,
                         StreamStruct &s, bool sep_files) :
  SkelStruct_C_Common (items, name, file_name, s, sep_files), num_of_methods (-1),
  num_of_normal_strings (-1)
{
}

SkelStructC::~SkelStructC()
{
}

void
SkelStructC::generate()
{
  if (num_of_methods < 0)
    analyze_items ();

  string struct_name (name + struct_suffix);
  string headername_include = struct_name;

  Utils::toUpper(headername_include);

  c_header_gen_class::set_structname (struct_name);
  genfunction_gen_class::set_structname (struct_name);
  strcntfunction_gen_class::set_structname (struct_name);
  initstructfun_gen_class::set_structname (struct_name);
  genstrfunction_gen_class::set_structname (struct_name);

  string author = "by " AUTHOR " " EMAIL;
  string other_comments =  HOMEPAGE;

  c_header_gen_class::set_genname (name);
  genfunction_gen_class::set_genname (name);
  strcntfunction_gen_class::set_genname (name);
  genstrfunction_gen_class::set_genname (name);

  set_headernameinclude (headername_include + "_H");
  c_header_gen_class::set_package (PACKAGE);
  if (! no_gen_version)
    c_header_gen_class::set_version (VERSION);
  c_header_gen_class::set_author (author);
  c_header_gen_class::set_othercomments (other_comments);
  c_source_gen_class::set_package (PACKAGE);
  if (! no_gen_version)
    c_source_gen_class::set_version (VERSION);
  c_source_gen_class::set_author (author);
  c_source_gen_class::set_othercomments (other_comments);
  set_headerfile (file_name);

  generate_c_header (*streamstruct.header_stream);

  streamstruct.header_stream->flush ();
}

void
SkelStructC::generate_fields(ostream &stream, unsigned int indent)
{
  VarSetIterator it;
  const VarSet &var_set = skel_struct->getVarSet();
  string indent_string (indent, ' ');
  skelitem_type item_type;

  for (it = var_set.begin (); it != var_set.end (); ++it)
    {
      item_type = (*it)->getType ();
      if (canBeString( item_type ))
        {
          stream << indent_string;
          stream << "const char *" << **it << ";\n";
        }
      else if (item_type == BOOL_TYPE)
        {
          stream << indent_string;
          stream << "short " << **it << ";\n";
        }
      else if (item_type == INT_TYPE)
        {
          stream << indent_string;
          stream << "int " << **it << ";\n";
        }
    }
}

void
SkelStructC::generate_genparameters(ostream &stream, unsigned int indent)
{
  VarSetIterator it;
  const VarSet &var_set = skel_struct->getVarSet();
  skelitem_type item_type;

  for (it = var_set.begin (); it != var_set.end (); ++it)
    {
      item_type = (*it)->getType ();
      if (canBeString( item_type ))
        {
          stream << ", " << "const char *" << **it;
        }
      else if (item_type == BOOL_TYPE)
        {
          stream << ", " << "short " << **it;
        }
      else if (item_type == INT_TYPE)
        {
          stream << ", " << "int " << **it;
        }
    }
}

void
SkelStructC::generate_genstring(ostream &stream, unsigned int indent)
{
  if (sep_files)
    return;

  generate_genstringfun( stream, indent);
}

void
SkelStructC::generate_genstringfun(ostream &stream, unsigned int indent)
{
  if (! has_expand_strings ())
    return;

  genstringfun_gen_class genstring;
  genstring.generate_genstringfun (stream, indent);
}

void
SkelStructC::generate_genconvfun(ostream &stream, unsigned int indent)
{
  if (! has_ints_to_generate() && ! has_booleans_to_generate())
    return;

  c_convert_gen_class gen;
  gen.set_hasints(has_ints_to_generate());
  gen.set_hasbools(has_booleans_to_generate());
  gen.generate_c_convert (stream, indent);
}

void
SkelStructC::generate_genconv(ostream &stream, unsigned int indent)
{
  if (sep_files)
    return;

  generate_genconvfun (stream, indent);
}

void
SkelStructC::generate_genfieldinit(ostream &stream, unsigned int indent)
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
          stream << "record->" << **it << " = 0;\n";
        }
    }
}

void
SkelStructC::generate_assignfields(ostream &stream, unsigned int indent)
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
          stream << "record." << **it << " = " << **it << ";\n";
        }
    }
}

void
SkelStructC::generate_strgeninstructions(ostream &stream, unsigned int indent)
{
  SkelStructCString cstring_gen (*this);
  cstring_gen.start_generation (stream, indent);
}

void
SkelStructC::generate_funbody(ostream &stream, unsigned int indent)
{
  if (sep_files)
    {
      generate_c_source (*streamstruct.source_stream, 0);

      streamstruct.source_stream->flush ();
    }
  else
    {
      generate_genfunction (stream, 0);
      generate_genstrfunction (stream, 0);
      generate_strcntfunction (stream, 0);
      generate_initstructfun (stream, 0);
    }
}

void
SkelStructC::generate_genfunbody(ostream &stream, unsigned int indent)
{
  generate_genfunction (stream, 0);
  generate_genstrfunction (stream, 0);
  generate_strcntfunction (stream, 0);
  generate_initstructfun (stream, 0);
}

void
SkelStructC::generate_externfunctions(ostream &stream, unsigned int indent)
{
  VarSetIterator it;
  const VarSet &var_set = skel_struct->getVarSet();
  skelitem_type item_type;
  extern_function_gen_class extfun_gen;

  for (it = var_set.begin (); it != var_set.end (); ++it)
    {
      item_type = (*it)->getType ();

      if (item_type == METHOD_TYPE)
        {
          extfun_gen.set_name ((*it)->getText ());
          extfun_gen.set_structname (c_header_gen_class::structname);
          extfun_gen.generate_extern_function (stream, indent);

          stream << endl;
          stream << endl;
        }
    }
}

void
SkelStructC::generate_geninstructions(ostream &stream, unsigned int indent)
{
  gen_generate_instructions (stream, indent);
}

void
SkelStructC::generate_compleninstr(ostream &stream, unsigned int indent)
{
  SkelStructStrCnt strcnt (*this);

  int const_len = strcnt.compute_length (stream, indent);

  ostringstream const_len_s;
  const_len_s << const_len;

  set_constlen (const_len_s.str ());
}

void
SkelStructC::call_external_function(ostream &stream, const string &name,
                                    unsigned int indent)
{
  callextfun_gen_class callext;
  callext.set_name (name);
  callext.generate_callextfun (stream, indent);
  stream << endl;
}

void
SkelStructC::std_generation(ostream &stream, const string &s)
{
  stream << "fprintf (stream, \"%s\", "
         << s << ");\n";
}

void
SkelStructC::variable_generation(ostream &stream, const string &name,
                                 const skelitem_type &type,
                                 unsigned int indent)
{
  ostringstream cvar;

  if (canBeString( type ) || expand_tabs) {
    outputcvar_gen_class cvar_gen (name);
    cvar_gen.generate_outputcvar (cvar);
  } else {
    cvar << field_prefix() << name;
  }

  // instead of relying on the convert functions, since printf
  // can handle integers, we use this feature directly
  if (expand_tabs)
    stream << "generate_string (" + cvar.str () +
      ", stream, indent + strlen (indent_str));\n";
  else {
    if (canBeString( type ))
      stream << "fprintf (stream, \"%s\", "
             << cvar.str () << ");\n";
    else if (type == BOOL_TYPE)
      stream << "fprintf (stream, \"%s\", ("
          << cvar.str () << " ? \"true\" : \"false\"));\n";
    else
      stream << "fprintf (stream, \"%d\", "
          << cvar.str () << ");\n";
  }
}

