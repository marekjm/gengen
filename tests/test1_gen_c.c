#include <stdio.h>

#include "test1_c.h"

int
main()
{
  struct test1_gen_struct gen_struct;
  gen_struct.i = "foo";
  generate_test1(stdout, &gen_struct, 0);
  printf("\n");
  gen_struct.i = "bar";
  generate_test1(stdout, &gen_struct, 0);
  printf("\n");

  return 0;
}
