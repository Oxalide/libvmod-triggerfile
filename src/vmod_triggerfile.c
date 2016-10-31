#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "vcl.h"
#include "vrt.h"
#include "cache/cache.h"

#include "vcc_if.h"

int
init_function(const struct vrt_ctx *ctx, struct vmod_priv *priv,
    enum vcl_event_e e)
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
