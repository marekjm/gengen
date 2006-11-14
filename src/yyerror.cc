/*
  Called by yyparse on error.
 */

#include "errormanager.h"

extern int line;

void
yyerror (const char *s)
{
  print_error(s, line);
}

