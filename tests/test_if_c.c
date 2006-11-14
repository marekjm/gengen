#include "test_if_c.h"

int
main()
{
  test_if_gen_struct gen;
  gen.myvar = "\"fooval\"";
  gen.mydef = "foodef";
  gen.boolvar = 0;
  gen.intvar = 0;
  gen.intvarcomp = 0;
  gen.stringvar = "bar";
  gen.stringvarcomp = "ba";

  generate_test_if (stdout, &gen, 0);

  return 0;
}
