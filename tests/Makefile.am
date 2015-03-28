# Copyright (C) 2002-2008 Lorenzo Bettini <http://www.lorenzobettini.it>
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

SUBDIRS = otherdir

SUFFIXES = .err .cc_skel .err_test .cc_skel .h .cc_skel _c.h .cc_skel _lua.lua

PROGEXE = $(top_builddir)/src/$(PACKAGE)$(EXEEXT)
PROGEXE_C = $(PROGEXE) --output-format "c"
PROGEXE_LUA = $(PROGEXE) --output-format "lua"
PROGNAME = $(PROGEXE) --no-gen-version 2>> $(VERBOSEOUT)

GENERATE = $(PROGNAME)
GENERATE_C = $(PROGNAME) --output-format "c"
GENERATE_LUA = $(PROGNAME) --output-format "lua"
GENERATEERR = $(PROGNAME) --test-mode

TEMP_H = __temp.h

.cc_skel.err:
	rm -f $*.h $*.cc && $(GENERATEERR) -i $< > $@ 2>&1

.cc_skel.err_test:
	rm -f $*.h $*.cc && $(GENERATEERR) -i $< > $@ 2>&1

test_cicle_tabs.h: $(srcdir)/test_cicle_tabs.cc_skel
	$(GENERATE) -i $(srcdir)/test_cicle_tabs.cc_skel --file-name $@ --gen-name test_cicle --expand-tabs

test_cicle_tabs_c.h: $(srcdir)/test_cicle_tabs.cc_skel
	$(GENERATE_C) -i $(srcdir)/test_cicle_tabs.cc_skel --file-name $@ --gen-name test_cicle --expand-tabs

test_cicle_tabs_lua.lua: $(srcdir)/test_cicle_tabs.cc_skel
	$(GENERATE_LUA) -i $(srcdir)/test_cicle_tabs.cc_skel --file-name $@ --gen-name test_cicle --expand-tabs

.cc_skel.h:
	$(GENERATE) -i $< --file-name $@ --gen-name $* 

.cc_skel_c.h:
	$(GENERATE_C) -i $< --file-name $@ --gen-name $*

.cc_skel_lua.lua:
	$(GENERATE_LUA) -i $< --file-name $@ --gen-name $*

# the cp is useful when building on a different directory
# since the sources are also deleted during `make check`
# see also clean-gen-files:

VERBOSEOUTPUT=verbose.output
VERBOSEOUT=verbose.out

ERRFILES = alreadydef.cc_skel alreadydef2.cc_skel alreadydef3.cc_skel \
notbool.cc_skel notbool2.cc_skel notbool3.cc_skel \
notsametype.cc_skel notsametype2.cc_skel
ERRFILES_OUTPUT = alreadydef.err alreadydef2.err alreadydef3.err \
notbool.err notbool2.err notbool3.err \
notsametype.err notsametype2.err

EXTRA_DIST = test_vars.cc_skel test_cicle.cc_skel \
test_cicle_tabs.cc_skel test_body_loop.cc_skel test_body_loop_lua.skel \
loop.cc_skel test_subst.cc_skel test_subst.cc_skel test_iter.cc_skel \
test1.cc_skel example_text.text_skel example_fundef.cc_skel \
test_vars.cc test_cicle.cc test_cicle_str.cc test_cicle2_main.c test_cicle2_main.lua \
test_iter.cc test_cicle_m.cc test_subst.cc \
test_subst2_main.cc test1_gen.cc test1_gen_c.c test1_gen.lua \
example_text_gen.cc example_text_gen_c.c example_text_gen_lua.lua \
example_fundef_gen.cc \
test_cicle_c.c test_cicle_gen_lua.lua test_cicle_str_c.c test_cicle2_c.c test_cicle2_lua.lua \
test_cicle_cstring.c test_cicle_c_cc.cc \
test_cicle_tabs.cc test_cicle_tabs_c.c test_cicle_tabs_gen_lua.lua \
test_if.cc_skel test_if.cc test_if_c.c test_if_gen_lua.lua \
test_types.cc_skel test_types.cc test_types_c.c test_types_gen_lua.lua \
$(GENERATED_TESTS) \
$(ERRFILES) \
$(ERRFILES_OUTPUT) \
$(VERBOSEOUTPUT) \
valgrind_tests.sh.in \
valgrind_gengen_tests.sh.in

BUILT_EXECUTABLES = test_vars$(EXEEXT) gen_test_vars$(EXEEXT) \
test_cicle$(EXEEXT) test_cicle_str$(EXEEXT) test_cicle_tabs$(EXEEXT) \
gen_test_cicle$(EXEEXT) gen_test_cicle_str$(EXEEXT) \
test_cicle_m$(EXEEXT) gen_test_cicle_m$(EXEEXT) test_subst$(EXEEXT) \
gen_test_subst$(EXEEXT) test_iter$(EXEEXT) \
gen_test_iter$(EXEEXT) test_subst2_prog$(EXEEXT) test1_gen$(EXEEXT) test1_gen_c$(EXEEXT) test1_gen_lua$(EXEEXT) \
example_text_gen$(EXEEXT) example_text_gen_c$(EXEEXT) example_text_gen_lua$(EXEEXT) \
example_fundef_gen$(EXEEXT) \
test_cicle_c$(EXEEXT) test_cicle_gen_lua$(EXEEXT) test_cicle_str_c$(EXEEXT) \
test_cicle2_c$(EXEEXT) test_cicle2_lua$(EXEEXT) test_cicle_c_cc$(EXEEXT) \
test_cicle_tabs_c$(EXEEXT) test_cicle_tabs_gen_lua$(EXEEXT) \
gen_test_cicle_c$(EXEEXT) gen_test_cicle_str_c$(EXEEXT) \
gen_test_cicle_c_cc$(EXEEXT) \
test_cicle_cstring$(EXEEXT) gen_test_cicle_cstring$(EXEEXT) \
gen_test_cicle_tabs$(EXEEXT) \
test_if$(EXEEXT) test_if_c$(EXEEXT) test_if_gen_lua$(EXEEXT) \
test_types$(EXEEXT) test_types_c$(EXEEXT) test_types_gen_lua$(EXEEXT)

# we do not want that generated sources are included in the tar ball
# so we have to do things manually:
# xxx_BUILT_SRC are the sources for that specific program (executable)
# those files that are not generated have to be included in EXTRA_DIST

test_vars_BUILT_SRC = test_vars.cc
gen_test_vars_BUILT_SRC = gen_test_vars.cc
test_cicle_BUILT_SRC = test_cicle.cc
test_cicle_str_BUILT_SRC = test_cicle_str.cc
test_cicle_tabs_BUILT_SRC = test_cicle_tabs.cc
test_cicle_tabs_c_BUILT_SRC = test_cicle_tabs_c.c
gen_test_cicle_BUILT_SRC = gen_test_cicle.cc
gen_test_cicle_str_BUILT_SRC = gen_test_cicle_str.cc
gen_test_cicle_c_BUILT_SRC = gen_test_cicle_c.cc
gen_test_cicle_str_c_BUILT_SRC = gen_test_cicle_str_c.cc
gen_test_cicle_c_cc_BUILT_SRC = gen_test_cicle_c_cc.cc
gen_test_cicle_cstring_BUILT_SRC = gen_test_cicle_cstring.cc
gen_test_cicle_tabs_BUILT_SRC = gen_test_cicle_tabs.cc
gen_test_cicle_tabs_c_BUILT_SRC = gen_test_cicle_tabs_c.cc
test_iter_BUILT_SRC = test_iter.cc
gen_test_iter_BUILT_SRC = gen_test_iter.cc
test_cicle_m_BUILT_SRC = test_cicle_m.cc
gen_test_cicle_m_BUILT_SRC = gen_test_cicle_m.cc
test_subst_BUILT_SRC = test_subst.cc
# ensure that the file containing main does not have the same name
# otherwise problems under cygwin sometimes
test_subst2_prog_BUILT_SRC = test_subst2.cc test_subst2_main.cc
gen_test_subst_BUILT_SRC = gen_test_subst.cc
test1_gen_BUILT_SRC = test1_gen.cc
test1_gen_c_BUILT_SRC = test1_gen_c.c
example_text_gen_BUILT_SRC = example_text_gen.cc
example_text_gen_c_BUILT_SRC = example_text_gen_c.c
example_fundef_gen_BUILT_SRC = example_fundef_gen.cc
test_cicle_c_BUILT_SRC = test_cicle_c.c
test_cicle_str_c_BUILT_SRC = test_cicle_str_c.c
test_cicle2_c_BUILT_SRC = test_cicle2_c.c test_cicle2_main.c
test_cicle_cstring_BUILT_SRC = test_cicle_cstring.c
test_cicle_c_cc_BUILT_SRC = test_cicle_c_cc.cc
test_if_BUILT_SRC = test_if.cc
test_if_c_BUILT_SRC = test_if_c.c
test_types_BUILT_SRC = test_types.cc
test_types_c_BUILT_SRC = test_types_c.c

BUILT_SOURCES = test_vars.h gen_test_vars.cc test_cicle.h \
test_cicle_tabs.h \
test_body_loop.h gen_test_cicle.cc gen_test_cicle_str.cc \
loop.h gen_test_cicle_m.cc \
test_subst.h gen_test_subst.cc test_iter.h gen_test_iter.cc \
test_subst2.h test_subst2.cc \
test1.h test1_c.h test1_lua.lua \
example_text.h example_text_c.h example_text_lua.lua example_fundef.h \
test_cicle_c.h test_cicle_lua.lua test_cicle2_c.h test_cicle2_lua.header \
test_cicle2_c.c test_cicle2_lua.lua test_body_loop_c.h test_body_loop_lua.lua \
test_cicle_tabs_c.h test_cicle_tabs_lua.lua \
gen_test_cicle_c.cc gen_test_cicle_str_c.cc \
gen_test_cicle_cstring.cc gen_test_cicle_c_cc.cc \
gen_test_cicle_tabs.cc gen_test_cicle_tabs_c.cc \
test_if.h test_if_c.h test_if_lua.lua \
test_types.h test_types_c.h test_types_lua.lua

# there seem to be problems if using *.test in EXTRA_DIST:
# it works with `make dist` but not with `make distcheck`
GENERATED_TESTS = test_vars.h.test gen_test_vars.cc.test test_cicle.h.test \
test_body_loop.h.test gen_test_cicle.cc.test gen_test_cicle_str.cc.test \
loop.h.test \
gen_test_cicle_m.cc.test \
test_subst.h.test gen_test_subst.cc.test test_iter.h.test \
gen_test_iter.cc.test \
test_subst2.h.test test_subst2.cc.test \
test1.h.test test1_c.h.test test1_lua.lua.test example_text.h.test example_text_c.h.test example_text_lua.lua.test \
example_fundef.h.test \
test_cicle_c.h.test test_cicle_lua.lua.test \
test_cicle2_c.h.test test_cicle2_lua.header.test \
test_cicle2_c.c.test test_cicle2_lua.lua.test \
test_body_loop_c.h.test test_body_loop_lua.lua.test \
gen_test_cicle_c.cc.test \
gen_test_cicle_str_c.cc.test \
gen_test_cicle_c_cc.cc.test \
gen_test_cicle_cstring.cc.test \
test_cicle_tabs.h.test \
test_cicle_tabs_c.h.test \
test_cicle_tabs_lua.lua.test \
gen_test_cicle_tabs.cc.test \
gen_test_cicle_tabs_c.cc.test \
test_if.h.test test_if_c.h.test test_if_lua.lua.test \
test_types.h.test test_types_c.h.test test_types_lua.lua.test

CXXLD = $(CXX)
COMPILE_BUILT_EXEC = $(CXXLD) -DHAVE_CONFIG_H $(AM_CXXFLAGS) $(CXXFLAGS) $(AM_LDFLAGS) $(LDFLAGS) -I$(top_builddir)/tests/ -I$(top_srcdir)/src/ -I$(top_builddir)/ -o $@ $^
CCLD = $(CC)
COMPILE_C_BUILT_EXEC = $(CCLD) $(AM_CXXFLAGS) $(CXXFLAGS) $(AM_LDFLAGS) $(LDFLAGS) -I$(top_builddir)/tests/ -o $@ $^


test_vars$(EXEEXT): $(test_vars_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

gen_test_vars$(EXEEXT): $(gen_test_vars_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

test_cicle$(EXEEXT): $(test_cicle_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

test_cicle_str$(EXEEXT): $(test_cicle_str_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

gen_test_cicle$(EXEEXT): $(gen_test_cicle_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

gen_test_cicle_str$(EXEEXT): $(gen_test_cicle_str_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

test_iter$(EXEEXT): $(test_iter_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

gen_test_iter$(EXEEXT): $(gen_test_iter_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

test_cicle_m$(EXEEXT): $(test_cicle_m_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

test_cicle_tabs.cc: test_cicle_tabs.h
test_cicle_tabs$(EXEEXT): $(test_cicle_tabs_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

test_cicle_tabs_c$(EXEEXT): $(test_cicle_tabs_c_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

gen_test_cicle_m$(EXEEXT): $(gen_test_cicle_m_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

test_subst$(EXEEXT): $(test_subst_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

test_subst2_prog$(EXEEXT): $(test_subst2_prog_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

gen_test_subst$(EXEEXT): $(gen_test_subst_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

test1_gen$(EXEEXT): $(test1_gen_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

test1_gen_c$(EXEEXT): $(test1_gen_c_BUILT_SRC)
	$(COMPILE_C_BUILT_EXEC)

example_text_gen$(EXEEXT): $(example_text_gen_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

example_text_gen_c$(EXEEXT): $(example_text_gen_c_BUILT_SRC)
	$(COMPILE_C_BUILT_EXEC)

example_fundef_gen$(EXEEXT): $(example_fundef_gen_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

example_text.h: example_text.text_skel
	$(GENERATE) -i $< --file-name $@ --gen-name example_text

example_text_c.h: example_text.text_skel
	$(GENERATE) -i $< --file-name $@ --gen-name example_text --output-format=c

example_text_lua.lua: example_text.text_skel
	$(GENERATE) -i $< --file-name $@ --gen-name example_text --output-format=lua

test_if$(EXEEXT): $(test_if_BUILT_SRC) test_if.h
	$(COMPILE_BUILT_EXEC)

test_if_c$(EXEEXT): $(test_if_c_BUILT_SRC) test_if_c.h
	$(COMPILE_BUILT_EXEC)

test_types$(EXEEXT): $(test_types_BUILT_SRC) test_types.h
	$(COMPILE_BUILT_EXEC)

test_types_c$(EXEEXT): $(test_types_c_BUILT_SRC) test_types_c.h
	$(COMPILE_BUILT_EXEC)

test_subst2.cc: test_subst2.h
test_subst2.h: test_subst.cc_skel
	$(GENERATE) -i $< --file-name $@ --gen-name test_subst --separate-files

test_cicle2_c.c: test_cicle2_c.h
test_cicle2_c.h: test_cicle.cc_skel
	$(GENERATE_C) -i $< --file-name $@ --gen-name test_cicle --separate-files

test_cicle2_lua.lua: test_cicle2_lua.header
test_cicle2_lua.header: test_cicle.cc_skel
	$(GENERATE_LUA) -i $< --file-name $@ --gen-name test_cicle --separate-files

gen_test_vars.cc: test_vars$(EXEEXT)
	$(top_builddir)/tests/$< > $@

gen_test_cicle.cc: test_cicle$(EXEEXT)
	$(top_builddir)/tests/$< > $@

gen_test_cicle_str.cc: test_cicle_str$(EXEEXT)
	$(top_builddir)/tests/$< > $@

gen_test_iter.cc: test_iter$(EXEEXT)
	$(top_builddir)/tests/$< > $@

gen_test_cicle_m.cc: test_cicle_m$(EXEEXT)
	$(top_builddir)/tests/$< > $@

gen_test_subst.cc: test_subst$(EXEEXT)
	$(top_builddir)/tests/$< > $@

test_cicle_c$(EXEEXT): $(test_cicle_c_BUILT_SRC)
	$(COMPILE_C_BUILT_EXEC)

test_cicle_str_c$(EXEEXT): $(test_cicle_str_c_BUILT_SRC)
	$(COMPILE_C_BUILT_EXEC)

test_cicle2_c$(EXEEXT): $(test_cicle2_c_BUILT_SRC)
	$(COMPILE_C_BUILT_EXEC)

test_cicle_cstring$(EXEEXT): $(test_cicle_cstring_BUILT_SRC)
	$(COMPILE_C_BUILT_EXEC)

test_cicle_c_cc$(EXEEXT): $(test_cicle_c_cc_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

gen_test_cicle_c$(EXEEXT): $(gen_test_cicle_c_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

gen_test_cicle_str_c$(EXEEXT): $(gen_test_cicle_str_c_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

gen_test_cicle_c_cc$(EXEEXT): $(gen_test_cicle_c_cc_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

gen_test_cicle_c.cc: test_cicle_c$(EXEEXT)
	$(top_builddir)/tests/$< > $@

gen_test_cicle_str_c.cc: test_cicle_str_c$(EXEEXT)
	$(top_builddir)/tests/$< > $@

gen_test_cicle_c_cc.cc: test_cicle_c_cc$(EXEEXT)
	$(top_builddir)/tests/$< > $@

gen_test_cicle_cstring$(EXEEXT): $(gen_test_cicle_cstring_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

gen_test_cicle_cstring.cc: test_cicle_cstring$(EXEEXT)
	$(top_builddir)/tests/$< > $@

gen_test_cicle_tabs$(EXEEXT): $(gen_test_cicle_tabs_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

gen_test_cicle_tabs_c$(EXEEXT): $(gen_test_cicle_tabs_c_BUILT_SRC)
	$(COMPILE_BUILT_EXEC)

gen_test_cicle_tabs.cc: test_cicle_tabs$(EXEEXT)
	$(top_builddir)/tests/$< > $@

gen_test_cicle_tabs_c.cc: test_cicle_tabs_c$(EXEEXT)
	$(top_builddir)/tests/$< > $@

#test_cicle_m$(EXEEXT): test_cicle.h loop.h

check-am: clean
	$(MAKE) $(AM_MAKEFLAGS) $(BUILT_SOURCES)
	$(MAKE) $(AM_MAKEFLAGS) $(BUILT_EXECUTABLES)
	$(MAKE) $(AM_MAKEFLAGS) check-diff

my-check: clean
	$(MAKE) $(AM_MAKEFLAGS) $(BUILT_SOURCES)
	$(MAKE) $(AM_MAKEFLAGS) check-diff

check-gen: clean-gen-files
	$(MAKE) $(AM_MAKEFLAGS) $(BUILT_EXECUTABLES)

store-backup: $(BUILT_SOURCES)
	rm -f *.test; \
	for source in $(BUILT_SOURCES); do \
	  back_output="`echo $$source.test`"; \
	  echo "saving $$back_output"; \
	  cp $$source $(srcdir)/$$back_output; \
	done

check-diff: $(ERRFILES_OUTPUT)
	rm -f *.err_test; \
	for source in $(BUILT_SOURCES); do \
	  back_output="`echo $$source.test`"; \
	  echo "diff $$source $$back_output"; \
	  if ! diff $$source $(srcdir)/$$back_output; \
	  then errors=1; fi; \
	done && \
	for source in $(ERRFILES); do \
	  orig_output="`echo $$source|sed 's/\.cc\_skel/\.err/'`"; \
	  back_output="`echo $$orig_output\_test`"; \
	  rm -f $$back_output; \
	  $(GENERATEERR) -i $(srcdir)/$$source > $$back_output 2>&1; \
	  echo "diff $$orig_output $$back_output"; \
	  if ! diff $(srcdir)/$$orig_output $$back_output; \
	  then errors=1; fi; \
	done && \
	echo "diff verbose.output verbose.out"; \
	if ! diff $(srcdir)/$(VERBOSEOUTPUT) $(VERBOSEOUT); \
	then errors=1; fi; \
	test -z $$errors

check-err:
	for source in $(ERRFILES); do \
	  orig_output="`echo $$source|sed 's/\.cc\_skel/\.err/'`"; \
	  back_output="`echo $$orig_output\_test`"; \
	  rm -f $$back_output; \
	  $(GENERATEERR) -i $(srcdir)/$$source > $$back_output 2>&1; \
	  echo "diff $$orig_output $$back_output"; \
	  if ! diff $(srcdir)/$$orig_output $$back_output; \
	  then errors=1; fi; \
	done && test -z $$errors

check-valgrind: valgrind_tests.sh
	$(SHELL) valgrind_tests.sh $(BUILT_EXECUTABLES)

check-gengen-valgrind: valgrind_gengen_tests.sh
	$(SHELL) valgrind_gengen_tests.sh $(PROGEXE) -i $(srcdir)/test_cicle_tabs.cc_skel --file-name temp_file --gen-name test_cicle --expand-tabs
	$(SHELL) valgrind_gengen_tests.sh $(PROGEXE_C) -i $(srcdir)/test_cicle_tabs.cc_skel --file-name temp_file --gen-name test_cicle --expand-tabs
	$(SHELL) valgrind_gengen_tests.sh $(PROGEXE_LUA) -i $(srcdir)/test_cicle_tabs.cc_skel --file-name temp_file --gen-name test_cicle --expand-tabs
	rm -f temp_file

CLEANFILES = $(BUILT_SOURCES) $(BUILT_EXECUTABLES) *.err_test $(VERBOSEOUT)
