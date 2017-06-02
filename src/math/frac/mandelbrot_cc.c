#include "fractal.h"

#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void mandelbrot_cc(iframe * const ifrm, cmplx const * const min, cmplx const * const delta, ssize_t const threads)
{
	ssize_t y;
	ssize_t current;
	uint *sm;

	sm = mmap(NULL, sizeof(uint) * ifrm->width * ifrm->height, PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, 0, 0);

	y = 0;
	current = 0;

	while (TRUE)
	{
		if (current == threads)
		{
			wait(NULL);
			current--;
		}

		if (y == ifrm->height)
		{
			if (current == 0)
				break;
			continue;
		}

		if (fork() == 0)
		{
			mandelbrot_row(sm + y * ifrm->width, ifrm->width, y, ifrm->iterations, min, delta);
			exit(EXIT_SUCCESS);
		}

		current++;
		y++;
	}

	memcpy(ifrm->frame, sm, sizeof(uint) * ifrm->width * ifrm->height);
	munmap(sm, sizeof(uint) * ifrm->width * ifrm->height);
}
