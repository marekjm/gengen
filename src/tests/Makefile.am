# Copyright (C) 2008 Lorenzo Bettini <http://www.lorenzobettini.it>
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

AM_CPPFLAGS = -I$(top_srcdir)/lib -I$(top_builddir)/lib -I@top_srcdir@/src/

LDADD = $(top_builddir)/lib/libgnu.a $(top_builddir)/src/libgengen.a

EXTRA_PROGRAMS = test_replace test_exp_generator test_exp_checker test_type_env

TESTS = test_replace test_exp_checker test_exp_generator test_type_env

test_replace_SOURCES = test_replace.cc

test_exp_generator_SOURCES = test_exp_generator.cpp 

test_exp_checker_SOURCES = test_exp_checker.cpp

test_type_env_SOURCES = test_type_env.cpp

CLEANFILES = $(TESTS)
