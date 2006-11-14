#include "test_types_c.h"

int
main()
{
  test_types_gen_struct gen;
  gen.mystring = "hello_world";
  gen.myint = 1971;
  gen.mybool = 1;

  generate_test_types (stdout, &gen, 0);

  return 0;
}
