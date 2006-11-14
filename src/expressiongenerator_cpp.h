//
// C++ Interface: expressiongenerator_cpp
//
// Description: 
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef EXPRESSIONGENERATOR_CPP_H
#define EXPRESSIONGENERATOR_CPP_H

#include <expressionvisitor.hpp>

#include <iostream>
#include <map>
#include <string>

/**
an expression generator targeted for C++ output

	@author Lorenzo Bettini <http://www.lorenzobettini.it>
 */
class ExpressionGeneratorCpp : public ExpressionVisitor
{
  protected:
    std::ostream *out;
    typedef std::map<std::string, std::string> OperatorMap;
    /// translation table for operators
    OperatorMap operatorMap;
    /// the prefix for non const base expressions, i.e., variables
    std::string prefix;
    
  public:
    ExpressionGeneratorCpp(std::ostream &o);

    void setStream(std::ostream &o) { out = &o; }
    
    virtual void visit(Expression *exp);
    virtual void visit(UnaryExpression *exp);
    virtual void visit(BinaryExpression *exp);
    
    void setPrefix(const std::string &p) { prefix = p; }
};

#endif
