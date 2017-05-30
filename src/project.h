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

	double init_r_min;
	double init_r_max;
	double init_i_min;
	double init_i_max;

	char *debug_plt_path;
	char *iframe_dir_path;
	char allow_host;


	cmplx tar;
//based on current iteration
	cmplx r;
	cmplx i;
} project;

void project_free(project * const);
BOOL project_exists(char const * const);
BOOL project_create(project const * const, char const * const);
BOOL project_read(project * const, char const * const);
BOOL project_uptar(cmplx const * const, char const * const);

#endif
