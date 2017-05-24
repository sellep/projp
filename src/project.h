#ifndef __P_PROJECT_H
#define __P_PROJECT_H

#include "defs.h"

#define CFG_NAME "projp.cfg"

typedef struct
{
	uint width;
	uint height;
	uint iterations;
	dec tar_r;
	dec tar_i;
} project;

BOOL project_exists(char const * const);
BOOL project_read(project * * const, char const * const);
BOOL project_write(project const * const, char const * const);

#endif