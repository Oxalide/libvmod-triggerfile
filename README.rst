============
vmod_triggerfile
============

----------------------
Varnish triggerfile Module
----------------------

:Author: Maxime de Roucy
:Date: 2016-10-31
:Version: 2
:Manual section: 3

SYNOPSIS
========

import triggerfile;

DESCRIPTION
===========

Test if a file exist an return a boolean.

FUNCTIONS
=========

exist
-----

Prototype
        ::

                exist(STRING S)
Return value
	BOOL
Description
	Test if a file exist.
triggerfile
        ::

                if (req.url == "/httpprobe") {
                  if (triggerfile.exist("/space/out-of-the-pool"))
                  {
                    error 404 "KO";
                  }
                  else
                  {
                    error 200 "OK";
                  }
                }


INSTALLATION
============

The source tree is based on autotools to configure the building.

Building requires the Varnish header files and uses pkg-config to find
the necessary paths.

Usage::

 ./autogen.sh
 ./configure

If you have installed Varnish to a non-standard directory, call
``autogen.sh`` and ``configure`` with ``PKG_CONFIG_PATH`` pointing to
the appropriate path. For instance, when varnishd configure was called
with ``--prefix=$PREFIX``, use

::

 export PKG_CONFIG_PATH=${PREFIX}/lib/pkgconfig
 export ACLOCAL_PATH=${PREFIX}/share/aclocal

The module will inherit its prefix from Varnish, unless you specify a
different ``--prefix`` when running the ``configure`` script for this
module.

Make targets:

* make - builds the vmod.
* make install - installs your vmod.

If you build a dist tarball, you don't need any of the autotools or
pkg-config. You can build the module simply by running::

 ./configure
 make

Installation directories
------------------------

By default, the vmod ``configure`` script installs the built vmod in the
directory relevant to the prefix. The vmod installation directory can be
overridden by passing the ``vmoddir`` variable to ``make install``.

USAGE EXAMPLE
=============

In your VCL you could then use this vmod along the following lines::

        import triggerfile;

        sub vcl_recv {
          if (req.url == "/httpprobe") {
            if (triggerfile.exist("/space/out-of-the-pool"))
            {
              error 404 "KO";
            }
            else
            {
              error 200 "OK";
            }
          }

          …

HISTORY
=======

Lots of sources of this vmod comes from libvmod-example.

    https://github.com/varnish/libvmod-example
