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

Usage::

 ./configure VARNISHSRC=DIR [VMODDIR=DIR]

`VARNISHSRC` is the directory of the Varnish source tree for which to
compile your vmod. Both the `VARNISHSRC` and `VARNISHSRC/include`
will be added to the include search paths for your module.

Optionally you can also set the vmod install directory by adding
`VMODDIR=DIR` (defaults to the pkg-config discovered directory from your
Varnish installation).

Make targets:

* make - builds the vmod
* make install - installs your vmod in `VMODDIR`

DEBIAN
======

To build the libvmod-triggerfile Debian package ::

 # apt-get install apt-transport-https curl
 # curl https://repo.varnish-cache.org/GPG-key.txt | apt-key add -
 # echo "deb https://repo.varnish-cache.org/debian/ `lsb_release -s -c` varnish-3.0" >> /etc/apt/sources.list
 # echo "deb-src https://repo.varnish-cache.org/debian/ `lsb_release -s -c` varnish-3.0" >> /etc/apt/sources.list
 # apt-get update
 # apt-get build-dep varnish=3.0.7-1~wheezy
 # su - builduser
 $ mkdir varnish
 $ cd varnish
 $ apt-get source varnish=3.0.7-1~wheezy
 $ cd varnish-3.0.7
 $ debuild -us -uc
 $ cd ~
 …
 $ cd libvmod-triggerfile
 $ rm -rf .git*
 $ debuild -e"DEBIAN_VARNISH_SRC=/home/userbuild/varnish/varnish-3.0.7/" -us -uc

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
