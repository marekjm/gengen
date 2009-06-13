#include "unaryexpression.h"
#include "binaryexpression.h"
#include "expressiongenerator_c.h"
#include "my_sstream.h"
#include "asserttest.h"
#include <iostream>

#define printOut std::cout << "output: " << out.str() << std::endl;

int
main()
{
  Expression *constExp1 = new Expression("10");
  Expression *constExp2 = new Expression("a");
  UnaryExpression *unaryExp = new UnaryExpression("not a", "not", constExp2);
  BinaryExpression *binExp = new BinaryExpression("10 or ( not a )",
      "or", constExp1, unaryExp);
  
  std::ostringstream out;
  
  ExpressionGeneratorC expgen(out);

  expgen.visit_DB( binExp );
  
  printOut;
  int res = assertEquals("( 10 || ( ! a ) )", out.str());
  
  delete binExp;
  
  binExp = new BinaryExpression("foo <= bar", "<=",
                                new Expression("foo", STRING_TYPE),
                                new Expression("bar", STRING_TYPE));
  
  out.str("");
  expgen.setStream( out );
  expgen.visit_DB( binExp );
  
  printOut;
  res += assertEquals("( foo && bar && strcmp( foo, bar ) <= 0 )", out.str());
  
  binExp->getLeftExpression()->setIsConst( true );
  out.str("");
  expgen.setStream( out );
  expgen.visit_DB( binExp );
  printOut;
  res += assertEquals("( bar && strcmp( foo, bar ) <= 0 )", out.str());
  
  binExp->getRightExpression()->setIsConst( true );
  out.str("");
  expgen.setStream( out );
  expgen.visit_DB( binExp );
  printOut;
  res += assertEquals("( strcmp( foo, bar ) <= 0 )", out.str());

  binExp->getLeftExpression()->setIsConst( false );
  out.str("");
  expgen.setStream( out );
  expgen.visit_DB( binExp );
  printOut;
  res += assertEquals("( foo && strcmp( foo, bar ) <= 0 )", out.str());
  
  ExpressionGeneratorCpp expgencpp(out);
  
  out.str("");
  expgencpp.visit_DB( binExp );
  
  printOut;
  res += assertEquals("( foo <= bar )", out.str());
  
  delete binExp;
  
  return res;
}
