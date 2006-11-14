/*
  In this example we use multiple inheritance and derive
  from both generate-classes
*/

#include "test_cicle.h"
#include "loop.h"

class my_test_gen_class : 
  public test_cicle_gen_class, public loop_gen_class
{
public:
  void generate_loop(ostream &stream, unsigned int indent)
  {
    loop_gen_class::generate_loop (stream, indent);
  }

  virtual void generate_return_st(ostream &stream, unsigned int indent)
  {
    stream << "return 0;";
  }
};

int
main()
{
  my_test_gen_class gen;

  gen.set_loopnum ("10");
  gen.set_start ("1");
  gen.set_end ("10");

  gen.generate_test_cicle (std::cout);

  return 0;
}
