//
// C++ Interface: skelstruct_c_common
//
// Description:
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef SKELSTRUCT_C_COMMON_H
#define SKELSTRUCT_C_COMMON_H

#include <skelstruct.hpp>

#include "my_sstream.h"

class ExpressionGeneratorCpp;

/**
A base class that contains shared methods for C and C++ related generation code

@author Lorenzo Bettini
*/
class SkelStruct_C_Cpp_Common : public SkelStruct
{
  protected:
    /// the generator for expressions
    ExpressionGeneratorCpp *expGen;
    
public:
    SkelStruct_C_Cpp_Common(SkelItems* items, const string& n, const string& file, StreamStruct& s, bool sep);
    virtual ~SkelStruct_C_Cpp_Common();
    
    virtual void if_generation(const string &exp, const string &then_branch,
                             const string &else_branch, ostream &stream,
                             unsigned int indent);
    virtual const string field_prefix() { return ""; }
    
    virtual void exp_generation( Expression *exp, ostream &stream );
    
    /**
     * This is the factory method used to create an ExpressionGenerator 
     * 
     * @return The created ExpressionGenerator
     */
    virtual ExpressionGeneratorCpp *createExpGen(ostream &stream) = 0;
};

/**
A base class that contains shared methods for C related generation code

@author Lorenzo Bettini
*/
class SkelStruct_C_Common : public SkelStruct_C_Cpp_Common
{
public:
    SkelStruct_C_Common(SkelItems* items, const string& n, const string& file, StreamStruct& s, bool sep);

    virtual const string field_prefix() { return "record->"; }
    
    virtual ExpressionGeneratorCpp *createExpGen(ostream &stream);
};


#endif
