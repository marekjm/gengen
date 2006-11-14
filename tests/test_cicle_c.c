#include "test_cicle_c.h"
#include "test_body_loop_c.h"

void generate_loop(FILE *stream, struct test_cicle_gen_struct *foo, 
                   unsigned int indent)
{
  struct test_body_loop_gen_struct s;
  init_test_body_loop_gen_struct (&s);
  s.start = "1";
  s.end = "10";

  generate_test_body_loop (stream, &s, indent);
}

void generate_return_st(FILE *stream, struct test_cicle_gen_struct *foo, 
                        unsigned int indent)
{
}

int
main()
{
  struct test_cicle_gen_struct s;

  init_test_cicle_gen_struct (&s);
  s.loopnum = "10";
  s.return_st = "return 0;";

  generate_test_cicle (stdout, &s, 0);

  return 0;
}
