#include <iostream>

using std::cout;
using std::endl;

#include "test1.h"

int
main()
{
  test1_gen_class gen_class;
  gen_class.set_i("foo");
  gen_class.generate_test1(cout);
  cout << endl;
  gen_class.set_i("bar");
  gen_class.generate_test1(cout);
  cout << endl;

  return 0;
}
