/* rely on the generate_string method that expands tabs for strings
 in this case, set_loop */

#include "test_cicle_tabs.h"
#include "test_body_loop.h"
#include "my_sstream.h"

int
main()
{
  ostringstream loop_str;
  test_body_loop_gen_class loop_gen;

  loop_gen.set_start ("1");
  loop_gen.set_end ("10");

  loop_gen.generate_test_body_loop (loop_str);

  test_cicle_gen_class gen;

  gen.set_loopnum ("10");
  gen.set_return_st ("return 0;");
  gen.set_loop (loop_str.str ());

  gen.generate_test_cicle (std::cout);

  return 0;
}
