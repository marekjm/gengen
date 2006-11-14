#include "test_cicle.h"
#include "test_body_loop.h"

class my_test_gen_class : 
  public test_cicle_gen_class
{
private:
  test_body_loop_gen_class &loop_gen;

public:
  my_test_gen_class(test_body_loop_gen_class &l) :
    loop_gen (l)
  {
  }

  virtual void generate_loop(ostream &stream, unsigned int indent)
  {
    loop_gen.generate_test_body_loop (stream, indent);
  }

  virtual void generate_return_st(ostream &stream, unsigned int indent)
  {}
};

int
main()
{
  test_body_loop_gen_class loop_gen;

  loop_gen.set_start ("1");
  loop_gen.set_end ("10");

  my_test_gen_class gen (loop_gen);

  gen.set_loopnum ("10");
  gen.set_return_st ("return 0;");

  gen.generate_test_cicle (std::cout);

  return 0;
}
