/**
 * C++ functions: asserttest.h
 *
 * Description: assert functions used for tests
 *
 * Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2005
 * Copyright: See COPYING file that comes with this distribution
 */


#ifndef _ASSERTTEST_H_
#define _ASSERTTEST_H_

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

int
assertEquals(const std::string &expected, const std::string &actual)
{
    if (expected != actual) {
        std::cerr << "assertEquals failed" << std::endl;
        std::cerr << "expected: " << expected << std::endl;
        std::cerr << "actual  : " << actual << std::endl;

        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}

int
assertEquals(bool expected, bool actual)
{
    if (expected != actual) {
        std::cerr << "assertEquals failed" << std::endl;
        std::cerr << "expected: " << expected << std::endl;
        std::cerr << "actual  : " << actual << std::endl;

        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}

int
assertTrue(bool exp, const std::string &desc = "")
{
  if (!exp) {
    if (desc != "")
      std::cerr << desc << std::endl;
    else
    	std::cerr << "assertion failed!" << std::endl;
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}

#endif /*_ASSERTTEST_H_*/
