
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NORMAL_T = 258,
     IDE_T = 259,
     ITERATION_T = 260,
     RELOP = 261,
     STRING_CONST = 262,
     NUM_CONST = 263,
     BOOL_CONST = 264,
     SKELITEMTYPE_T = 265,
     OPTVAL_T = 266,
     IF_T = 267,
     THEN_T = 268,
     ELSE_T = 269,
     ELSEIF_T = 270,
     ENDIF_T = 271,
     AND_T = 272,
     OR_T = 273,
     NOT_T = 274
   };
#endif
/* Tokens.  */
#define NORMAL_T 258
#define IDE_T 259
#define ITERATION_T 260
#define RELOP 261
#define STRING_CONST 262
#define NUM_CONST 263
#define BOOL_CONST 264
#define SKELITEMTYPE_T 265
#define OPTVAL_T 266
#define IF_T 267
#define THEN_T 268
#define ELSE_T 269
#define ELSEIF_T 270
#define ENDIF_T 271
#define AND_T 272
#define OR_T 273
#define NOT_T 274




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 58 "../../src/parser.yy"

  int tok ; /* command */
  char * string ; /* string : id, ... */
  bool boolean ;

  class SkelStruct *skelstruct;
  class SkelItems *skelitems;
  class SkelItemStruct *skelitemstruct;
  class NormalText *normaltext;
  class VarItem *varitem;
  class IfStruct *ifstruct;
  class Expression *expression;
  class UnaryExpression *unaryexpression;
  class BinaryExpression *binaryexpression;



/* Line 1676 of yacc.c  */
#line 108 "../../src/parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;

