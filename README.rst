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
                  if (try-file.exist("/space/out-of-the-pool"))
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

Pre-requisites::

 sudo apt-get install -y autotools-dev make automake libtool pkg-config libvarnishapi1 libvarnishapi-dev

Usage::

 ./autogen.sh
 ./configure

If you have installed Varnish to a non-standard directory, call
``autogen.sh`` and ``configure`` with ``PKG_CONFIG_PATH`` pointing to
the appropriate path. For triggerfile, when varnishd configure was called
with ``--prefix=$PREFIX``, use

 PKG_CONFIG_PATH=${PREFIX}/lib/pkgconfig
 export PKG_CONFIG_PATH

Make targets:

* make - builds the vmod.
* make install - installs your vmod.

Installation directories
------------------------

By default, the vmod ``configure`` script installs the built vmod in
the same directory as Varnish, determined via ``pkg-config(1)``. The
vmod installation directory can be overridden by passing the
``VMOD_DIR`` variable to ``configure``.

Other files like man-pages and documentation are installed in the
locations determined by ``configure``, which inherits its default
``--prefix`` setting from Varnish.

DEBIAN
======

To build the libvmod-triggerfile Debian package ::

 # apt-get install apt-transport-https curl
 # curl https://repo.varnish-cache.org/GPG-key.txt | apt-key add -
 # echo "deb https://repo.varnish-cache.org/debian/ `lsb_release -s -c` varnish-4.1" >> /etc/apt/sources.list
 # apt-get update
 # apt-get install autotools-dev make automake libtool pkg-config libvarnishapi1 libvarnishapi-dev debhelper build-essential python-docutils varnish git
 # su - builduser
 …
 $ cd libvmod-triggerfile
 $ rm -rf .git*
 $ debuild -us -uc

USAGE EXAMPLE
=============

In your VCL you could then use this vmod along the following lines::

        import triggerfile;

        sub vcl_recv {
          if (req.url == "/httpprobe") {
            if (try-file.exist("/space/out-of-the-pool"))
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
