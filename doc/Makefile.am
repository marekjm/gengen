# Copyright (C) 2002 Lorenzo Bettini <http://www.lorenzobettini.it>
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

SUFFIXES = .h.texinfo .h .cc.texinfo .cc .c.texinfo .c .h_skel.texinfo .h_skel .cc_skel.texinfo .cc_skel

AM_MAKEINFOHTMLFLAGS=--no-split

info_TEXINFOS = gengen.texinfo

# handled by texinfo
#gengen.html: $(srcdir)/gengen.texi
#	$(TEXI2HTML) -monolithic $< > $@ 

EXTRA_DIST = gengen.html index.html $(man_MANS) $(GENERATEDINFOS)

BUILT_SOURCES = $(GENERATEDINFOS)

gengendoc_DATA = gengen.html index.html

# man page
man_MANS = gengen.1

if NO_BUILDMAN
gengen.1: $(top_srcdir)/src/cmdline.ggo
	touch $@
else
gengen.1: $(top_srcdir)/src/cmdline.ggo
	$(HELP2MAN) $(top_builddir)/src/gengen > $@
endif

gengen.texinfo: $(GENERATEDINFOS)

GENERATEDINFOS = test1.cc_skel.texinfo test1_gen_c.c.texinfo test1_gen.cc.texinfo \
example_text_gen_c.c.texinfo example_text_gen.cc.texinfo \
example_fundef.cc_skel.texinfo example_fundef_gen.cc.texinfo

RUNSOURCEHIGHLIGHT=$(SOURCEHIGHLIGHT) -f texinfo --style-file=texinfo.style --output-dir=$(top_builddir)/doc/ --failsafe -o $@

if NO_SOURCEHIGHLIGHT

else
test1_gen_c.c.texinfo: $(top_srcdir)/tests/test1_gen_c.c
	$(RUNSOURCEHIGHLIGHT) -i $(top_srcdir)/tests/test1_gen_c.c

test1.cc_skel.texinfo: $(top_srcdir)/tests/test1.cc_skel
	$(RUNSOURCEHIGHLIGHT) -i $(top_srcdir)/tests/test1.cc_skel

test1_gen.cc_skel.texinfo: $(top_srcdir)/tests/test1_gen.cc_skel
	$(RUNSOURCEHIGHLIGHT) -i $(top_srcdir)/tests/test1_gen.cc_skel

example_text_gen_c.c.texinfo: $(top_srcdir)/tests/example_text_gen_c.c
	$(RUNSOURCEHIGHLIGHT) -i $(top_srcdir)/tests/example_text_gen_c.c

example_text_gen.cc.texinfo: $(top_srcdir)/tests/example_text_gen.cc
	$(RUNSOURCEHIGHLIGHT) -i $(top_srcdir)/tests/example_text_gen.cc

example_fundef.cc_skel.texinfo: $(top_srcdir)/tests/example_fundef.cc_skel
	$(RUNSOURCEHIGHLIGHT) -i $(top_srcdir)/tests/example_fundef.cc_skel

example_fundef_gen.cc.texinfo: $(top_srcdir)/tests/example_fundef_gen.cc
	$(RUNSOURCEHIGHLIGHT) -i $(top_srcdir)/tests/example_fundef_gen.cc
endif
