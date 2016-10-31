AM_CFLAGS = $(VARNISHAPI_CFLAGS) -Wall -Werror
AM_LDFLAGS = $(VARNISHAPI_LIBS) $(VMOD_LDFLAGS) $(CODE_COVERAGE_LDFLAGS)

vmod_LTLIBRARIES = libvmod_triggerfile.la

libvmod_triggerfile_la_SOURCES = \
	vmod_triggerfile.c

nodist_libvmod_triggerfile_la_SOURCES = \
	vcc_triggerfile_if.c \
	vcc_triggerfile_if.h

dist_man_MANS = vmod_triggerfile.3

@BUILD_VMOD_TRIGGERFILE@

AM_TESTS_ENVIRONMENT = \
	PATH="$(VMOD_TEST_PATH)" \
	LD_LIBRARY_PATH="$(VARNISH_LIBRARY_PATH)"
TEST_EXTENSIONS = .vtc
VTC_LOG_COMPILER = varnishtest -v
AM_VTC_LOG_FLAGS = -Dvmod_triggerfile="$(VMOD_TRIGGERFILE)"

TESTS = @VMOD_TESTS@

EXTRA_DIST = \
	vmod_triggerfile.vcc \
	$(VMOD_TESTS)
