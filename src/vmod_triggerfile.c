#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "vcl.h"
#include "vrt.h"
#include "cache/cache.h"

#include "vcc_if.h"

VCL_BOOL
vmod_exist(VRT_CTX, VCL_STRING name)
{
	if(access(name, F_OK) == 0)
		return 1 /* OK */;

	return 0 /* KO */;
}
