/*
 Called by yyparse on error.
 */

#include "errormanager.h"

extern int line;

void yyerror(const std::string &s) {
	print_error(s, line);
}

