#include <iostream>
#include "example_text.h"

using std::cout;
using std::endl;

int
main()
{
  example_text_gen_class gen_class;
  gen_class.set_name("an example");
  gen_class.set_progname("example_text_gen");
  gen_class.set_generator("Gengen");
  gen_class.set_version("1.0");

  gen_class.generate_example_text(cout);
  cout << endl;

  cout << endl;
  gen_class.set_name("another example");
  cout << "  ";
  gen_class.generate_example_text(cout, 2);
  cout << endl;

  return 0;
}
