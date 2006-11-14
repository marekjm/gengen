#include "unaryexpression.h"

#include "binaryexpression.h"

#include "expression.h"

#include "expressionvisitor.hpp"

void
ExpressionVisitor::visit_DB(Expression * exp)
{
  exp->dispatch_visit(this);
}

void
BinaryExpression::dispatch_visit(ExpressionVisitor *ExpressionVisitor_o)
{
  ExpressionVisitor_o->visit(this);
}

void
Expression::dispatch_visit(ExpressionVisitor *ExpressionVisitor_o)
{
  ExpressionVisitor_o->visit(this);
}

void
UnaryExpression::dispatch_visit(ExpressionVisitor *ExpressionVisitor_o)
{
  ExpressionVisitor_o->visit(this);
}

