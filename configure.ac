# Copyright (C) 2002-2010 Lorenzo Bettini <http://www.lorenzobettini.it>
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

dnl Process this file with autoconf to produce a configure script.
AC_INIT(gengen,1.4.2)

AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

dnl for automake
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE($PACKAGE_NAME, $PACKAGE_VERSION)

AC_SUBST(gengendatadir)
AC_SUBST(gengendocdir)

gengendatadir=$datadir/gengen
gengendocdir=$docdir

dnl Checks for C compiler.
AC_PROG_CC

dnl Use of GnuLib
gl_EARLY

dnl add options for non GNU compilers
AC_NONGNU_FLAGS

dnl Test for a gotcha in the Sun Forte Developer and, more recently the
dnl Sun ONE Studio, C++ compiler that causes an undef at link time if
dnl the code uses templates and "libx.a" archives are built using the
dnl standard `ar' technique.  `CC' creates a subdirectory set starting
dnl with one named "SunWC_cache" to build additional "*.o" files for the
dnl instantiated templates(?).  The normal way 'ar' is used doesn't work
dnl when generating archive ("libx.a") libraries and `CC' itself must be
dnl used.  The following is a hack provided by Paul Townsend <aab@purdue.edu>.
dnl
AC_MSG_CHECKING( checking whether to use ar cru or CC -xar -o )
cat <<EOF >conftest.c
int conftest(void){return 0;}
EOF
${CXX} -xar -o conftest.a conftest.c >/dev/null 2>&1
if test $? == 0; then
  ar_to_use="\$(CXX) -xar -o"
else
  ar_to_use="\$(AR) cru"
fi
AC_SUBST(ar_to_use)dnl
AC_MSG_RESULT( $ar_to_use )
rm -fr conftest.*

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T

# For gnulib.
gl_INIT

dnl executable extension
AC_EXEEXT

dnl Checks for C++ compiler.
AC_PROG_CXX
AC_LANG_CPLUSPLUS
AC_PROG_AWK

AC_PROG_INSTALL

dnl check for ranlib, for building common code
AC_PROG_RANLIB

dnl test for --enable-warnings command line option
AC_ARG_ENABLE( warnings, [  --enable-warnings       enable compiler warnings], AC_COMPILE_WARNINGS )

dnl check for STL
AC_CXX_HAVE_STL

dnl check for sstream.h
AC_CXX_HAVE_SSTREAM

dnl for yacc or bison
AC_PROG_YACC

dnl set some flags for yacc to generate header file
AC_SUBST(YFLAGS)dnl
YFLAGS="$YFLAGS -d"

dnl for lex or flex
AM_PROG_LEX

dnl Checks for libraries.
dnl Replace `main' with a function in -lfl:
AC_CHECK_LIB(fl, main)

dnl if (f)lex library is not present (yywrap won't be found) we provide
dnl a simple implementation (see yywrap.cc) which will be included in
dnl libobj and linked against the program (see src/Makefile.am)
dnl this works with flex generated files (I don't know about others)
AC_REPLACE_FUNCS(yywrap)

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(unistd.h)

dnl this is for testing purpose and development
AC_PATH_PROGS(VALGRIND, valgrind)

dnl this is only for developers who change src/cmdline.ggo file
dnl GNU gengetopt can be found at http://www.gnu.org/software/gengetopt
AC_PATH_PROGS(GENGETOPT, gengetopt)
AM_CONDITIONAL(NO_GENGETOPT, test -z "$ac_cv_path_GENGETOPT" )

dnl this is only for developers who use change command line options
AC_PATH_PROGS(HELP2MAN, help2man)
AM_CONDITIONAL(NO_HELP2MAN, test -z "$ac_cv_path_HELP2MAN" )

AM_CONDITIONAL(NO_BUILDMAN, test -z "$ac_cv_path_HELP2MAN" && test -z "$ac_cv_path_GENGETOPT")

dnl this is only for developers who use double dispatch
dnl doublecpp can be found at http://www.lorenzobettini.it/software/doublecpp
AC_PATH_PROGS(DOUBLECPP, doublecpp)
AM_CONDITIONAL(NO_DOUBLECPP, test -z "$ac_cv_path_DOUBLECPP" )

AC_PATH_PROGS(TAR, tar gtar)

AC_PATH_PROGS(TEXI2HTML, texi2html)

dnl this is only for highlighting source for documentation
dnl GNU source-highlight can be found at 
dnl http://www.gnu.org/software/src-highlite
AC_PATH_PROGS(SOURCEHIGHLIGHT, source-highlight)

AM_CONDITIONAL(NO_SOURCEHIGHLIGHT, test -z "$ac_cv_path_SOURCEHIGHLIGHT" )

dnl some scripts (e.g., valgrind_test.sh) need bash extensions
AC_PATH_PROGS(BASH_SHELL, bash sh)


AC_CONFIG_FILES(Makefile lib/Makefile src/Makefile src/includes/Makefile 
          src/skels/Makefile src/tests/Makefile
          doc/Makefile tests/Makefile tests/otherdir/Makefile
          tests/valgrind_tests.sh tests/valgrind_gengen_tests.sh)

AC_OUTPUT
