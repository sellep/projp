#include "defs.h"
#include "project.h"
#include "utils/file.h"
#include "media/media.h"
#include "windows/windows.h"
#include "math/frac/fractal.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	project proj;
	palette plt;

	if (!project_read_args(&proj, argc, argv))
		return 1;

	if (proj.debug_plt_path == NULL)
	{
		fprintf(stderr, "debug palette path not configured!");
		return 1;
	}

	if (!palette_read(&plt, proj.debug_plt_path))
	{
		fprintf(stderr, "failed to read palette %s\n", proj.debug_plt_path);
		return 1;
	}

	//invoke mandelbrot on host
	cmplx delta;
	cmplx min;
	iframe ifrm;
	color *pix;

	iframe_init(&ifrm, &proj);
	pix = (color*) malloc(sizeof(color) * proj.width * proj.height);

	while (TRUE)
	{
		min.r = proj.init_r_min;
		min.i = proj.init_i_min;

		//compute delta
		dec_sub(&delta.r, &proj.init_r_max, &proj.init_r_min);
		dec_sub(&delta.i, &proj.init_i_max, &proj.init_i_min);
		dec_idiv(&delta.r, &delta.r, proj.width);
		dec_idiv(&delta.i, &delta.i, proj.height);

		//invoke mandelbrot
		mandelbrot_cc(&ifrm, &min, &delta, proj.host_threads);

		if (!iframe_write_dbg(&ifrm, "/tmp/iframe_dbg.txt"))
		{
			printf("failed to write debug iframe\n");
			goto exit;
		}

		if (!iframe_map(pix, &ifrm, &plt))
		{
			printf("failed to map iframe\n");
			goto exit;
		}

		if (!bmp_write(proj.width, proj.height, pix, "/home/pascal/projp/res/frac.bmp"))
		{
			printf("failed to write bitmap\n");
			goto exit;
		}

		break;
	}

	//int status = show_debug("/home/pascal/earth.jpg");

exit:
	free(pix);
	iframe_free(&ifrm);
	palette_free(&plt);
	project_free(&proj);
	return 0;
}
