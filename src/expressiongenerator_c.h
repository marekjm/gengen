//
// C++ Interface: expressiongenerator_c
//
// Description: 
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef EXPRESSIONGENERATOR_C_H
#define EXPRESSIONGENERATOR_C_H

#include "expressiongenerator_cpp.h"

/**
an expression generator targeted for C output

	@author Lorenzo Bettini <http://www.lorenzobettini.it>
*/
class ExpressionGeneratorC : public ExpressionGeneratorCpp
{
public:
  ExpressionGeneratorC(std::ostream &o);

    virtual void visit(BinaryExpression *exp);
};

#endif
