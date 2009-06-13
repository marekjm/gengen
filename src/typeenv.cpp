//
// C++ Implementation: typeenv
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "typeenv.h"

bool TypeEnv::hasType(const std::string &id) {
	return (typeEnv[id] != "");
}

const ExpressionType &TypeEnv::getType(const std::string &id) {
	if (typeEnv[id] == "") {
		// by default an id has type string
		typeEnv[id] = STRING_TYPE;
	}

	return typeEnv[id];
}

bool TypeEnv::setType(const std::string &id, const ExpressionType &type) {
	if (typeEnv[id] != "") {
		// it's OK only if we try to set the same type already associated
		return typeEnv[id] == type;
	}

	typeEnv[id] = type;
	return true;
}
