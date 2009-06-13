//
//
// C++ Interface: skelstruct_c
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2003
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef SKELSTRUCT_C_H
#define SKELSTRUCT_C_H

#include "skelstruct_c_common.h"
#include "c_header.h"
#include "genfunction.h"
#include "c_source.h"
#include "strcntfunction.h"
#include "initstructfun.h"
#include "genstrfunction.h"

class SkelStructC : public SkelStruct_C_Common, public c_header_gen_class,
                    public genfunction_gen_class, public c_source_gen_class,
                    public strcntfunction_gen_class, public initstructfun_gen_class,
                    public genstrfunction_gen_class
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
  SkelStructC (SkelItems *items,
               const string &n, const string &file_name, StreamStruct &s,
               bool sep_files);
  virtual ~SkelStructC();

  virtual void generate();
};

#endif // SKELSTRUCT_C_H
