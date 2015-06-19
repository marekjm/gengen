# Copyright (C) 2002 Lorenzo Bettini <http://www.lorenzobettini.it>
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

SUFFIXES = .h .h_skel

PROGNAME = $(top_builddir)/src/$(PACKAGE)$(EXEEXT)

GENERATE = $(PROGNAME)

# it may happen, usually if the sources have been downloaded from a
# repository, that .h_skel is more recent than the generated files, but
# they cannot be re-generated, even because gengen has
# to be built first.

.h_skel.h:
	if test -f $(PROGNAME); then \
	$(GENERATE) -i $< --file-name $@ --gen-name $* --expand-tabs; \
	fi

BUILT_SOURCES = class.h genmethod.h genmethod_body.h \
setmethod.h abstrmethod.h cc_source.h copyright.h \
c_header.h lua_header.h extern_function.h extern_function_lua.h \
genfunction.h genfunction_lua.h c_source.h lua_source.h strcntfunction.h strcntfunction_lua.h \
callmeth.h callextfun.h callextfun_lua.h initstructfun.h initstructfun_lua.h genstrfunction.h genstrfunction_lua.h \
genstringfun.h genstringfun_lua.h outputcvar.h outputluavar.h ifgen_c.h ifgen_lua.h \
c_convert.h lua_convert.h

EXTRA_DIST = class.h_skel genmethod.h_skel \
setmethod.h_skel abstrmethod.h_skel genmethod_body.h_skel \
cc_source.h_skel lua_source.h_skel copyright.h_skel \
c_header.h_skel lua_header.h_skel extern_function.h_skel extern_function_lua.h_skel \
genfunction.h_skel genfunction_lua.h_skel c_source.h_skel strcntfunction.h_skel strcntfunction_lua.h_skel \
callmeth.h_skel callextfun.h_skel callextfun_lua.h_skel initstructfun.h_skel initstructfun_lua.h_skel \
genstrfunction.h_skel genstrfunction_lua.h_skel \
genstringfun.h_skel genstringfun_lua.h_skel outputcvar.h_skel outputluavar.h_skel \
ifgen_c.h_skel ifgen_lua.h_skel \
c_convert.h_skel lua_convert.h_skel \
$(BUILT_SOURCES)

clean-built:
	rm -f $(BUILT_SOURCES)
