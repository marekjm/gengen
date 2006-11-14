#include "test_types.h"

int
main()
{
  test_types_gen_class gen;
  gen.set_mystring ("hello_world");
  gen.set_myint (1971);
  gen.set_mybool (true);

  gen.generate_test_types (std::cout);

  return 0;
}
