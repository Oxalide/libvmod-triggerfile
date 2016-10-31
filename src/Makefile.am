AM_CPPFLAGS = -I$(VARNISHSRC)/include -I$(VARNISHSRC)

vmoddir = $(VMODDIR)
vmod_LTLIBRARIES = libvmod_triggerfile.la

libvmod_triggerfile_la_LDFLAGS = -module -export-dynamic -avoid-version -shared

libvmod_triggerfile_la_SOURCES = \
	vcc_if.c \
	vcc_if.h \
	vmod_triggerfile.c

vcc_if.c vcc_if.h: $(VARNISHSRC)/lib/libvmod_std/vmod.py $(top_srcdir)/src/vmod_triggerfile.vcc
	@PYTHON@ $(VARNISHSRC)/lib/libvmod_std/vmod.py $(top_srcdir)/src/vmod_triggerfile.vcc

EXTRA_DIST = \
	vmod_triggerfile.vcc

CLEANFILES = $(builddir)/vcc_if.c $(builddir)/vcc_if.h
