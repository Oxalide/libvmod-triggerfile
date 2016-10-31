#include <stdlib.h>
#include <unistd.h>

#include "vrt.h"
#include "bin/varnishd/cache.h"

#include "vcc_if.h"

int
init_function(struct vmod_priv *priv, const struct VCL_conf *conf)
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
