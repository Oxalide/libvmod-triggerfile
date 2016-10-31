#include "config.h"

#include <stdio.h>
#include <stdlib.h>

/* need vcl.h before vrt.h for vmod_evet_f typedef */
#include "vcl.h"
#include "vrt.h"
#include "cache/cache.h"

#include "vtim.h"
#include "vcc_triggerfile_if.h"

/*
 * handle vmod internal state, vmod init/fini and/or varnish callback
 * (un)registration here.
 *
 * this vmod doesn't have any state, so there is nothing to be done
 *
 */

int __match_proto__(vmod_event_f)
event_function(VRT_CTX, struct vmod_priv *priv, enum vcl_event_e e)
{
	return (0);
}

unsigned
vmod_exist(struct sess *sp, const char *name)
{
	if(access(name, F_OK) == 0)
		return 1 /* OK */;

	return 0 /* KO */;
}
