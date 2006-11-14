/* rely on the generate_string method that expands tabs for strings
 in this case, the loop field */

#include "test_cicle_tabs_c.h"
#include "test_body_loop_c.h"

int
main()
{
  struct test_cicle_gen_struct s;
  struct test_body_loop_gen_struct l;
  char *loop_str;

  init_test_body_loop_gen_struct (&l);
  l.start = "1";
  l.end = "10";

  loop_str = genstring_test_body_loop (&l, 0);

  init_test_cicle_gen_struct (&s);
  s.loopnum = "10";
  s.return_st = "return 0;";
  s.loop = loop_str;

  generate_test_cicle (stdout, &s, 0);

  free (loop_str);

  return 0;
}
