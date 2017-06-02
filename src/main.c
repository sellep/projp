#include "defs.h"
#include "project.h"
#include "utils/file.h"
#include "media/media.h"
#include "windows/windows.h"
#include "math/frac/fractal.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

BOOL open_project(project * const proj, int const argc, char const * const * const argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "missing project file path!\n");
		return FALSE;
	}

	if (!project_read(proj, argv[1]))
	{
		fprintf(stderr, "failed to load project\n");
		return FALSE;
	}

	return TRUE;
}

void palette_ensure(char const * const path, size_t const iterations)
{
	palette plt;
	color *bas;
	size_t bas_len;
	size_t i;

	if (fexists(path))
		return;

	plt.len = iterations;
	plt.clr = (color*) malloc(sizeof(color) * iterations);

	bas_len = iterations / 100;
	bas = (color*) malloc(sizeof(color) * bas_len);

	bas[0].r = 0;
	bas[0].g = 0;
	bas[0].b = 0;
	bas[bas_len - 1].r = 0;
	bas[bas_len - 1].g = 0;
	bas[bas_len - 1].b = 0;

	for (i = 1; i < bas_len - 1; i++)
	{
		color_rand(bas + i);
	}

	palette_ipol(&plt, bas, bas_len);
	palette_write(&plt, path);

	free(plt.clr);
	free(bas);
}

int main(int argc, char *argv[])
{
	project proj;
	palette plt;

	if (!open_project(&proj, argc, argv))
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
	iframe ifrm;
	color *pix;

	iframe_init(&ifrm, &proj);
	pix = (color*) malloc(sizeof(color) * proj.width * proj.height);

	while (TRUE)
	{
		//compute delta
		dec_sub(&delta.r, &proj.init_r_max, &proj.init_r_min);
		dec_sub(&delta.i, &proj.init_i_max, &proj.init_i_min);
		dec_idiv(&delta.r, &delta.r, proj.width);
		dec_idiv(&delta.i, &delta.i, proj.height);

		//invoke mandelbrot
		//->missing multiple core implementation
		mandelbrot(&ifrm, &proj.init_r_min, &proj.init_i_min, &delta);

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

		if (!bmp_write(proj.width, proj.height, pix, "/tmp/frac.bmp"))
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
