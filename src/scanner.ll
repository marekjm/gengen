%{
/*
 * Copyright (C) 2002, Lorenzo Bettini <http://www.lorenzobettini.it>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <string.h>
#include <string>

#include "skelitemtype.h"
#include "parser.h"

extern int line ;

#define PUSH(s) yy_push_state(s);
#define POP() yy_pop_state();

//#define VERBSCAN
#ifdef VERBSCAN
#include <iostream>
#define VERB_SCAN(s) s
#else
#define VERB_SCAN(s)
#endif
#define VERB_SCAN2(s) VERB_SCAN(std::cerr << "line: " << line << " " << s << std::endl;)

using std::string;

static void
count_nl(const string &);

// defined by bison and flex
extern YYLTYPE yylloc ;

inline void
updateTokenInfo()
{
  yylloc.first_line = line ;
}


%}

%option stack nomain yylineno noyywrap nounput

ws [ ]+
tabs [\t]+

nl \n
cr \r

IDE [a-zA-Z_]([a-zA-Z0-9_])*

STRING \"[^\"\n]*\"
NUMCONST [0-9]+
BOOLCONST "true"|"false"

ifline {ws}*
ifline2 {ws}*{nl}?

%s VARITEM_STATE IFSTATE

%%

<INITIAL>"@@" { yylval.string = strdup (&yytext[1]); return NORMAL_T; }

<INITIAL>"@if@" { PUSH (IFSTATE); VERB_SCAN2("if"); return IF_T; }
<IFSTATE>"@then@" { POP(); VERB_SCAN2("then"); count_nl(yytext); return THEN_T; }
<INITIAL>"@else@" { VERB_SCAN2("else"); count_nl(yytext); return ELSE_T; }
<INITIAL>"@elseif@" { PUSH (IFSTATE); VERB_SCAN2("elseif"); count_nl(yytext); return ELSEIF_T; }
<INITIAL>"@endif@" { VERB_SCAN2("endif"); count_nl(yytext); return ENDIF_T; }

<INITIAL>{ifline}"@IF@" { PUSH (IFSTATE); VERB_SCAN2("IF"); return IF_T; }
<IFSTATE>"@THEN@"{ifline2} { POP(); VERB_SCAN2("THEN"); count_nl(yytext); return THEN_T; }
<INITIAL>{ifline}"@ELSE@"{ifline2} { VERB_SCAN2("ELSE"); count_nl(yytext); return ELSE_T; }
<INITIAL>"@ELSEIF@"{ifline2} { PUSH (IFSTATE); VERB_SCAN2("ELSEIF"); count_nl(yytext); return ELSEIF_T; }
<INITIAL>{ifline}"@ENDIF@"{ifline2} { VERB_SCAN2("ENDIF"); count_nl(yytext); return ENDIF_T; }

<IFSTATE>"and" { VERB_SCAN2("AND"); return AND_T; }
<IFSTATE>"(" { VERB_SCAN2("("); return '('; }
<IFSTATE>")" { VERB_SCAN2("("); return ')'; }
<IFSTATE>"or" { VERB_SCAN2("OR"); return OR_T; }
<IFSTATE>"not" { VERB_SCAN2("NOT"); return NOT_T; }
<IFSTATE>"!="|"="|"<"|">"|"<="|">=" { VERB_SCAN2(yytext); yylval.string = strdup (yytext); return RELOP; }
<IFSTATE>{STRING} { VERB_SCAN2("STRING_CONST"); yylval.string = strdup (yytext); updateTokenInfo(); return STRING_CONST; }
<IFSTATE>{NUMCONST} { VERB_SCAN2("NUM_CONST"); yylval.string = strdup (yytext); updateTokenInfo(); return NUM_CONST; }
<IFSTATE>{BOOLCONST} { VERB_SCAN2("BOOL_CONST"); yylval.string = strdup (yytext); updateTokenInfo(); return BOOL_CONST; }
<IFSTATE>{ws}* { VERB_SCAN2(yytext); }

<INITIAL>"@" { BEGIN VARITEM_STATE; return '@'; }
<VARITEM_STATE>"@" { BEGIN INITIAL; return '@'; }
<VARITEM_STATE,IFSTATE>":" { return ':'; }
<VARITEM_STATE>"{" { return '{'; }
<VARITEM_STATE>"}" { return '}'; }
<VARITEM_STATE>"=" { return '='; }
<VARITEM_STATE>"method" { yylval.string = strdup(METHOD_TYPE); return SKELITEMTYPE_T; }
<VARITEM_STATE,IFSTATE>"int" { yylval.string = strdup(INT_TYPE); return SKELITEMTYPE_T; }
<VARITEM_STATE,IFSTATE>"string" { yylval.string = strdup(STRING_TYPE); return SKELITEMTYPE_T; }
<VARITEM_STATE,IFSTATE>"bool" { yylval.string = strdup(BOOL_TYPE); return SKELITEMTYPE_T; }
<VARITEM_STATE>"true" { yylval.boolean = true; return OPTVAL_T; }
<VARITEM_STATE>"false" { yylval.boolean = false; return OPTVAL_T; }
<VARITEM_STATE>"iteration" { yylval.string = strdup (yytext); return ITERATION_T; }
<VARITEM_STATE,IFSTATE>[a-zA-Z_]([a-zA-Z0-9_])* { yylval.string = strdup (yytext); VERB_SCAN2("IDE"); updateTokenInfo(); return IDE_T; }

<INITIAL>\n { yylval.string = strdup (yytext); ++line ; VERB_SCAN2("NL"); return NORMAL_T; }
<IFSTATE>\n { ++line ; VERB_SCAN2("NL"); }

<INITIAL>[^@\n]* { yylval.string = strdup (yytext); VERB_SCAN2("NORMAL"); return NORMAL_T; }


%%

void
count_nl(const string &s)
{
  string app = s;
  string::size_type pos;

  VERB_SCAN2("*** STRING in count_nl: " + s);

  while ((pos = app.find("\n")) != string::npos)
  {
    ++line;
    app = app.substr(pos+1);
  }

  VERB_SCAN(std::cerr << "*** line after count_nl: " << line << std::endl);
}
