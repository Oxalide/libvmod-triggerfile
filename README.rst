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
