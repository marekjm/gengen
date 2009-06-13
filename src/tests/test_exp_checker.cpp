#include "unaryexpression.h"
#include "binaryexpression.h"
#include "expressionchecker.h"
#include "expressionoperators.h"
#include "asserttest.h"
#include <iostream>

#define printError std::cout << "error: " << expcheck.getError() << std::endl;

int
main()
{
  int res = 0;

  assertTrue(isEqualOp(string("=")), "not equal");
  assertTrue(!isBooleanOp(string("=")), "not boolean =");
  assertTrue(isEqualOp(std::string("=")), "not equal");
  assertTrue(!isBooleanOp(std::string("=")), "not boolean =");

  Expression *constExp1 = new Expression("10");
  Expression *constExp2 = new Expression("a");
  UnaryExpression *unaryExp = new UnaryExpression("not a", "not", constExp2);
  BinaryExpression *binExp = new BinaryExpression("10 or ( not a )",
      "or", constExp1, unaryExp);

  ExpressionChecker expcheck;

  Expression *constErrExp1 = new Expression("10", NOTYPE);

  expcheck.visit_DB( constErrExp1 );
  printError;

  res += assertEquals("untyped expression 10", expcheck.getError());

  expcheck.resetError();
  expcheck.visit_DB( binExp );
  printError;
  // although 10 is not a boolean expression,
  // we set its type to bool, just for testing
  res += assertEquals("", expcheck.getError());
  res += assertTrue(binExp->getExpressionType() == BOOL_TYPE,
                    "not boolean expression");

  expcheck.resetError();

  Expression *unaryWrong = new UnaryExpression("not 10", "not",
                                               new Expression("10", INT_TYPE));

  expcheck.visit_DB( unaryWrong );
  printError;
  res += assertEquals("10 is not a boolean expression", expcheck.getError());

  expcheck.resetError();

  Expression *binaryWrong = new BinaryExpression("a and b", "and",
      new Expression("a"), new Expression("b", INT_TYPE));

  expcheck.visit_DB( binaryWrong );
  printError;
  res += assertEquals
    ("a and b must have the same type\na has type bool, b has type int",
     expcheck.getError());

  expcheck.resetError();
  delete binaryWrong;
  binaryWrong = new BinaryExpression("a and b", "and",
      new Expression("a", INT_TYPE), new Expression("b", INT_TYPE));

  expcheck.visit_DB( binaryWrong );
  printError;
  res += assertEquals("a is not a boolean expression", expcheck.getError());

  expcheck.resetError();
  delete binaryWrong;
  binaryWrong = new BinaryExpression("a = b", "=",
                                     new Expression("a", INT_TYPE),
                                     new Expression("b", INT_TYPE));

  expcheck.visit_DB( binaryWrong );
  printError;
  res += assertEquals("", expcheck.getError());
  res += assertTrue(binaryWrong->getExpressionType() == BOOL_TYPE,
                    "not boolean expression");

  expcheck.resetError();
  delete binaryWrong;
  binaryWrong = new BinaryExpression("a <= b", "<=",
                                     new Expression("a", BOOL_TYPE),
                                     new Expression("b", BOOL_TYPE));

  expcheck.visit_DB( binaryWrong );
  printError;
  res += assertEquals("<= cannot act on boolean expressions a and b",
                      expcheck.getError());

  expcheck.resetError();
  delete binExp;
  binExp = new BinaryExpression("a <= b", "<=",
                                     new Expression("a", STRING_TYPE),
                                     new Expression("b", STRING_TYPE));

  expcheck.visit_DB( binExp );
  printError;
  res += assertEquals("", expcheck.getError());
  res += assertTrue(binExp->getExpressionType() == BOOL_TYPE,
                    "not boolean expression");

  delete binExp;
  delete constErrExp1;
  delete unaryWrong;
  delete binaryWrong;

  return res;
}
