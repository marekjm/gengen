//
// C++ Interface: expressionoperators
//
// Description: string constants for expression operators
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef EXPRESSIONOPERATORS
#define EXPRESSIONOPERATORS

#define ANDOP "and"
#define OROP "or"
#define NOTOP "not"
#define LESSOP "<"
#define GREATEROP ">"
#define EQUALOP "="
#define NEQUALOP "!="
#define LESSEOP "<="
#define GREATEREOP "=>"

#define isBooleanOp(op) (op == ANDOP || op == OROP)
#define isNotOp(op) (op == NOTOP)
#define isEqualOp(op) (op == EQUALOP)
#define isNEqualOp(op) (op == NEQUALOP)
#define isExactCompareOp(op) (op == EQUALOP) || (op == NEQUALOP)
#define isRelativeOp(op) (op == LESSOP || op == LESSEOP || op == GREATEROP || op == GREATEREOP)

#endif
