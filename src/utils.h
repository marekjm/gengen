//
// C++ Interface: utils
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef UTILS_H
#define UTILS_H

#include <string>

/**
generic utils functions (e.g., string manipulation)

	@author Lorenzo Bettini <http://www.lorenzobettini.it>
*/
class Utils{
public:
    /**
     * Capitalizes the passed string
     * @param s the string to capitalize
     */
    static void toUpper(std::string &s);

    /**
     * Lowerizes the passed string
     * @param s the string to lowerize
     */
    static void toLower(std::string &s);
};

#endif
