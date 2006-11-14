%{
/*
 * Copyright (C) 2002 Lorenzo Bettini <http://www.lorenzobettini.it>
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

#include <stdlib.h>
#include <stdio.h>

#include "yyerror.h"
#include "normaltext.h"
#include "varitem.h"
#include "skelstruct.hpp"
#include "mainskelstruct.h"
#include "skelfactory.h"
#include "mainskelfactory.h"
#include "skelitemoptions.h"
#include "ifstruct.h"
#include "unaryexpression.h"
#include "binaryexpression.h"
#include "expressionoperators.h"

//#define YYERROR_VERBOSE

int line = 1 ;

extern int yylex() ;
extern FILE *yyin ;

%}

%union {
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

  skelitem_type skel_item_type;
} ;

%token <string> NORMAL_T IDE_T ITERATION_T RELOP STRING_CONST NUM_CONST BOOL_CONST
%token <skel_item_type> SKELITEMTYPE_T
%token <boolean> OPTVAL_T
%token <tok> IF_T THEN_T ELSE_T ELSEIF_T ENDIF_T AND_T OR_T NOT_T

%type <skelitemstruct> possibletext
%type <skelitems> text iftext;
%type <normaltext> normaltext
%type <varitem> substvar
%type <string> option_name
%type <ifstruct> ifstruct elsestruct
%type <expression> expression boolexp relexp baseexp

%left AND_T
%left OR_T
%left NOT_T
%left RELOP

%%

prog : text
       {
         skel_items = $1;
       }
;

text : possibletext
       {
         $$ = new SkelItems;
         $$->add_item ($1);
       }
     | text possibletext
       {
         $1->add_item ($2);
         $$ = $1;
       }
;

possibletext : normaltext { $$ = $1; }
             | substvar { $$ = $1; }
             | ifstruct { $$ = $1; }
;

iftext : text { $$ = $1; }
       | { $$ = new SkelItems; }
;

normaltext : NORMAL_T
             {
               $$ = skel_factory->createNormalText ($1);
             }
;

substvar : '@' IDE_T '@'
           {
             $$ = skel_factory->createVarItem ($2, STRING_TYPE);
             $$->setInfo(@2.first_line);
           }
         | '@' IDE_T ':' SKELITEMTYPE_T '@'
           {
             $$ = skel_factory->createVarItem ($2, $4);
             $$->setInfo(@2.first_line);
           }
         | '@' IDE_T ':' SKELITEMTYPE_T '{' option_name '=' OPTVAL_T '}' '@'
           {
             SkelItemOptions options;
             options.iteration = $8;
             $$ = skel_factory->createVarItem ($2, $4, options);
             $$->setInfo(@2.first_line);
           }
;

option_name : ITERATION_T
;

ifstruct : IF_T expression THEN_T iftext ENDIF_T
           {
              $$ = new IfStruct($2, $4, 0);
           }
         | IF_T expression THEN_T iftext elsestruct
           {
              $$ = new IfStruct($2, $4, $5);
           }
;

elsestruct : ELSE_T iftext ENDIF_T
             {
               $$ = new IfStruct(0, $2);
             }
           | ELSEIF_T expression THEN_T iftext ENDIF_T
             {
               $$ = new IfStruct($2, $4, 0);
             }
           | ELSEIF_T expression THEN_T iftext elsestruct
             {
               $$ = new IfStruct($2, $4, $5);
             }
;

expression : boolexp
;

boolexp : relexp
        | boolexp AND_T relexp
{ $$ = new BinaryExpression( $1->getText() + " " + ANDOP + " " + $3->getText(), ANDOP, $1, $3) ; }
        | boolexp OR_T relexp
{ $$ = new BinaryExpression( $1->getText() + " " + OROP + " " + $3->getText(), OROP, $1, $3) ; }
;

relexp : baseexp
       | relexp RELOP baseexp
{ $$ = new BinaryExpression( $1->getText() + " " + $2 + " " + $3->getText(), $2, $1, $3) ; }
;

baseexp : IDE_T
          {
               $$ = new Expression($1);
               $$->setInfo(@1.first_line);
          }
        | IDE_T ':' SKELITEMTYPE_T
          {
               $$ = new Expression($1, $3);
               $$->setInfo(@1.first_line);
          }
        | STRING_CONST 
{ $$ = new Expression($1, STRING_TYPE); $$->setInfo(@1.first_line); $$->setIsConst(true); }
        | NUM_CONST 
{ $$ = new Expression($1, INT_TYPE); $$->setInfo(@1.first_line); $$->setIsConst(true); }
        | BOOL_CONST 
{ $$ = new Expression($1, BOOL_TYPE); $$->setInfo(@1.first_line); $$->setIsConst(true); }
        | '(' expression ')' { $$ = $2; }
        | NOT_T expression
{ $$ = new UnaryExpression(string() + NOTOP + " " + $2->getText(), NOTOP, $2); }
;

%%

