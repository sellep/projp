#ifndef __P_PROJECT_H
#define __P_PROJECT_H

#include "defs.h"
#include "math/dec.h"
#include "math/cmplx.h"

#define CFG_NAME "projp.cfg"
#define IFRAME_DIR_NAME "iframes"

typedef struct
{
	ssize_t width;
	ssize_t height;
	size_t iterations;
	cmplx tar;
//based on current iteration
	cmplx r;
	cmplx i;
} project;

BOOL project_exists(char const * const);
BOOL project_create(project const * const, char const * const);
BOOL project_read(project * const, char const * const);
BOOL project_uptar(cmplx const * const, char const * const);

#endif
