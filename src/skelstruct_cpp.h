/*
 * Copyright (C) 2002 Lorenzo Bettini <http://www.lorenzobettini.it>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef SKELSTRUCT_CPP_H
#define SKELSTRUCT_CPP_H

#include "skelstruct_c_common.h"
#include "class.h"
#include "genmethod.h"
#include "genmethod_body.h"
#include "cc_source.h"

/**
 * Class for generation of C++ code
 */
class SkelStructCpp : public SkelStruct_C_Cpp_Common, public class_gen_class,
                      public genmethod_gen_class,
                      public genmethod_body_gen_class,
                      public cc_source_gen_class
{
 protected:
  const string generate_init_defaults();

  const string generate_paramassignments();
  const string generate_params();

 public:
  // redefined from class_gen_class
  virtual void generate_fields (ostream &stream, unsigned int indent);
  virtual void generate_setmethods (ostream &stream, unsigned int indent);
  virtual void generate_generate (ostream &stream, unsigned int indent);

  // redefined from genmethod_gen_class
  virtual void generate_genmethbody(ostream &stream, unsigned int indent);

  // redefined from genmethod_body_gen_class
  virtual void generate_geninstructions(ostream &stream, unsigned int indent);

  // redefined from cc_source_gen_class
  virtual void generate_methodbody(ostream &stream, unsigned int indent);

  // redefined from SkelStruct
  virtual void call_external_function(ostream &stream, const string &name,
                                      unsigned int indent);
  virtual void std_generation(ostream &stream, const string &s);
  virtual void variable_generation(ostream &stream, const string &name,
                                   const skelitem_type &t,
                                   unsigned int indent);

  virtual ExpressionGeneratorCpp *createExpGen(ostream &stream);

 public:
  SkelStructCpp (SkelItems *items,
                 const string &n, const string &file_name, StreamStruct &s,
                 bool sep_files);
  virtual ~SkelStructCpp();

  virtual void generate();
};

#endif // SKELSTRUCT_CPP_H
