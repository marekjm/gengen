#include <stdio.h>
#include "example_text_c.h"

int
main()
{
  struct example_text_gen_struct gen_struct;
  init_example_text_gen_struct(&gen_struct);
  gen_struct.name = "an example";
  gen_struct.progname = "example_text_gen";
  gen_struct.generator = "Gengen";
  gen_struct.version = "1.0";

  generate_example_text(stdout, &gen_struct, 0);
  printf("\n");

  printf("\n");
  gen_struct.name = "another example";
  printf("  ");
  generate_example_text(stdout, &gen_struct, 2);
  printf("\n");

  return 0;
}
