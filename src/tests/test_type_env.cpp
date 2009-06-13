#include "typeenv.h"
#include "asserttest.h"
#include <iostream>

int main() {
	TypeEnv typeEnv;

	// by default a variable has type string
	assertEquals(typeEnv.getType("foo"), STRING_TYPE);

	assertTrue(!typeEnv.setType("foo", INT_TYPE));
	assertTrue(typeEnv.setType("foo", STRING_TYPE));

	assertTrue(typeEnv.setType("bar", INT_TYPE));
	assertTrue(typeEnv.setType("bar", INT_TYPE));
	assertEquals(typeEnv.getType("bar"), INT_TYPE);

	assertTrue(!typeEnv.hasType("foobar"));
	assertTrue(typeEnv.hasType("foo"));
	assertTrue(typeEnv.hasType("bar"));

	return EXIT_SUCCESS;
}
