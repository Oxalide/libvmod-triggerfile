#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* need vcl.h before vrt.h for vmod_evet_f typedef */
#include "vcl.h"
#include "vrt.h"
#include "cache/cache.h"

#include "vtim.h"
#include "vcc_triggerfile_if.h"

VCL_BOOL
vmod_exist(VRT_CTX, VCL_STRING name)
{
	if(access(name, F_OK) == 0)
		return 1 /* OK */;

	return 0 /* KO */;
}
