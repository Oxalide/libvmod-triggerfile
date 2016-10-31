AM_CPPFLAGS = @VMOD_INCLUDES@ -Wall -Werror

vmoddir = @VMOD_DIR@
vmod_LTLIBRARIES = libvmod_triggerfile.la

libvmod_triggerfile_la_LDFLAGS = -module -export-dynamic -avoid-version -shared

libvmod_triggerfile_la_SOURCES = \
	vmod_triggerfile.c

nodist_libvmod_triggerfile_la_SOURCES = \
	vcc_if.c \
	vcc_if.h

vmod_triggerfile.lo: vcc_if.c vcc_if.h

vcc_if.c: vcc_if.h

vcc_if.h: @VMODTOOL@ $(top_srcdir)/src/vmod_triggerfile.vcc
	@VMODTOOL@ $(top_srcdir)/src/vmod_triggerfile.vcc

VMOD_TESTS = $(top_srcdir)/src/tests/*.vtc
.PHONY: $(VMOD_TESTS)

$(top_srcdir)/src/tests/*.vtc: libvmod_triggerfile.la
	@VARNISHTEST@ -Dvarnishd=@VARNISHD@ -Dvmod_topbuild=$(abs_top_builddir) $@

check: $(VMOD_TESTS)

EXTRA_DIST = \
	vmod_triggerfile.vcc \
	$(VMOD_TESTS)

CLEANFILES = \
	$(builddir)/vcc_if.c \
	$(builddir)/vcc_if.h \
	$(builddir)/vmod_triggerfile.rst \
	$(builddir)/vmod_triggerfile.man.rst
