# Copyright (C) 2009 Lorenzo Bettini <http://www.lorenzobettini.it>
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

PROGEXE = $(top_builddir)/src/$(PACKAGE)$(EXEEXT) --output-dir=$(builddir) --force
PROGEXE_C = $(PROGEXE) --output-format "c"
PROGNAME = $(PROGEXE) --no-gen-version

GENERATE = $(PROGNAME)
GENERATE_C = $(PROGNAME) --output-format "c"

# check that --output-dir works and that path from #include are stripped
# the "./" in --file-name is to check whether the path is then excluded
# from the generated #include
check-am:
	$(GENERATE) -i $(srcdir)/../test_subst.cc_skel --file-name ./test_subst2.h --gen-name test_subst --separate-file
	$(GENERATE_C) -i $(srcdir)/../test_cicle.cc_skel --file-name ./test_cicle2_c.h --gen-name test_cicle --separate-files
	@echo expect no output from diff
	diff $(builddir)/../test_subst2.h test_subst2.h 
	diff $(builddir)/../test_subst2.cc test_subst2.cc 
	diff $(builddir)/../test_cicle2_c.h test_cicle2_c.h 
	diff $(builddir)/../test_cicle2_c.c test_cicle2_c.c 

CLEANFILES = test_subst2.h test_subst2.cc test_cicle2_c.h test_cicle2_c.c

