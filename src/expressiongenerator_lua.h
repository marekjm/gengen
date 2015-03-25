
//
// C++ Interface: expressiongenerator_lua
//
// Description: output Lua interpretation of expressions
//
//
// Author: Raman Gopalan <ramangopalan@gmail.com>
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef EXPRESSIONGENERATOR_LUA_H
#define EXPRESSIONGENERATOR_LUA_H

#include "expressionvisitor.hpp"

#include <iostream>
#include <map>
#include <string>

class ExpressionGeneratorLua : public ExpressionVisitor
{
  protected:
    std::ostream *out;
    typedef std::map<std::string, std::string> OperatorMap;
    /// translation table for operators
    OperatorMap operatorMap;
    /// the prefix for non const base expressions, i.e., variables
    std::string prefix;

  public:
    ExpressionGeneratorLua(std::ostream &o);

    void setStream(std::ostream &o) { out = &o; }

    virtual void visit(Expression *exp);
    virtual void visit(UnaryExpression *exp);
    virtual void visit(BinaryExpression *exp);

    void setPrefix(const std::string &p) { prefix = p; }
};

#endif
