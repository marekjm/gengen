#include "test_iter.h"
#include "test_body_loop.h"

using std::endl;

class my_test_gen_class : 
  public test_iter_gen_class
{
private:
  test_body_loop_gen_class &loop_gen;
  bool first_time;

public:
  my_test_gen_class(test_body_loop_gen_class &l) :
    loop_gen (l), first_time (true)
  {
  }

  virtual void generate_loop(ostream &stream, unsigned int indent)
  {
    if (first_time)
      {
        string indent_str (indent, ' ');

        stream << indent_str;
        loop_gen.generate_test_body_loop (stream, indent);
        stream << endl;
        stream << endl;
        stream << indent_str;
        loop_gen.set_start ("20");
        loop_gen.set_end ("30");
        loop_gen.generate_test_body_loop (stream, indent);
        stream << endl;
        first_time = false;
      }
  }
};

int
main()
{
  test_body_loop_gen_class loop_gen;

  loop_gen.set_start ("1");
  loop_gen.set_end ("10");

  my_test_gen_class gen (loop_gen);

  gen.set_test ("true");

  gen.generate_test_iter (std::cout);

  return 0;
}
