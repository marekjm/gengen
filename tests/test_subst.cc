#include <iostream>

#include "test_subst.h"

int
main()
{
  test_subst_gen_class gen;

  gen.generate_test_subst (std::cout);

  return 0;
}
