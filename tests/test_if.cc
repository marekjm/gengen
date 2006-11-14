#include "test_if.h"

int
main()
{
  test_if_gen_class gen;
  gen.set_myvar ("\"fooval\"");
  gen.set_mydef ("foodef");
  gen.set_boolvar (false);
  gen.set_intvar (0);
  gen.set_intvarcomp (0);
  gen.set_stringvar ("bar");
  gen.set_stringvarcomp ("ba");

  gen.generate_test_if (std::cout);

  return 0;
}
