#include "test_vars.h"

int
main()
{
  test_vars_gen_class gen;
  gen.set_myvar ("\"fooval\"");
  gen.set_mydef ("foodef");

  gen.generate_test_vars (std::cout);

  return 0;
}
