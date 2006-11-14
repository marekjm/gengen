#include <iostream>
#include "test1.h"
#include "example_fundef.h"

using std::cout;
using std::endl;

class my_fundef_gen : public example_fundef_gen_class
{
 public:
  virtual void generate_funbody(ostream &stream, unsigned int indent) {
    test1_gen_class body_gen;
    body_gen.set_i (param);
    body_gen.generate_test1 (stream, indent);
  }
};

int
main()
{
  my_fundef_gen fun_gen;
  fun_gen.set_rettype ("void");
  fun_gen.set_funname ("foo_fun");
  fun_gen.set_paramtype ("unsigned int");
  fun_gen.set_param ("bar");

  fun_gen.generate_example_fundef (std::cout);
  cout << endl;

  return (0);
}
