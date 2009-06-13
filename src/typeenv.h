//
// C++ Interface: typeenv
//
// Description: a type environment, associates to a variable a type
//
// FOR THE MOMENT THIS DOES NOT SEEM TO BE USEFUL
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef TYPEENV_H
#define TYPEENV_H

#include <map>
#include <string>
#include "expressiontype.h"

typedef std::map<std::string, ExpressionType> TypeEnvBase;

/**
 Maps type identifiers to types

 @author Lorenzo Bettini <http://www.lorenzobettini.it>
 */
class TypeEnv {
	TypeEnvBase typeEnv;
public:
	/**
	 * Returns whether there's a type associated with the id
	 *
	 * @param id
	 * @return whether there's a type associated with the id
	 */
	bool hasType(const std::string &id);

	/**
	 * Returns the type associated to id; if no type is associated,
	 * id is assumed of type string
	 *
	 * @param id
	 * @return the type associated to id
	 */
	const ExpressionType &getType(const std::string &id);

	/**
	 * Sets the type associated to id; if id has already a type, then
	 * returns false
	 *
	 * @param id
	 * @return whether the type association succeeded
	 */
	bool setType(const std::string &id, const ExpressionType &type);
};

#endif
