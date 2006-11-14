# Copyright (C) 2002 Lorenzo Bettini <http://www.lorenzobettini.it>
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

PROGNAME = $(top_builddir)/src/$(PACKAGE)$(EXEEXT)

GENERATE = $(PROGNAME)

%.h: %.h_skel
	$(GENERATE) -i $< --file-name $@ --gen-name $* --expand-tabs

BUILT_SOURCES = class.h genmethod.h genmethod_body.h \
setmethod.h abstrmethod.h cc_source.h copyright.h \
c_header.h extern_function.h genfunction.h c_source.h strcntfunction.h \
callmeth.h callextfun.h initstructfun.h genstrfunction.h \
genstringfun.h outputcvar.h ifgen_c.h \
c_convert.h

EXTRA_DIST = class.h_skel genmethod.h_skel \
setmethod.h_skel abstrmethod.h_skel genmethod_body.h_skel \
cc_source.h_skel copyright.h_skel \
c_header.h_skel extern_function.h_skel \
genfunction.h_skel c_source.h_skel strcntfunction.h_skel \
callmeth.h_skel callextfun.h_skel initstructfun.h_skel \
genstrfunction.h_skel \
genstringfun.h_skel outputcvar.h_skel \
ifgen_c.h_skel \
c_convert.h_skel \
$(BUILT_SOURCES)

clean-built:
	rm -f $(BUILT_SOURCES)
