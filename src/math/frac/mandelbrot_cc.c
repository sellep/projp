#include "fractal.h"

#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define IDX(buf, w, y)(buf+y*w)

void mandelbrot_cc(iframe * const ifrm, cmplx const * const min, cmplx const * const delta, ssize_t const threads)
{
	ssize_t forks;
	ssize_t current;
	uint *sm;

	sm = mmap(NULL, sizeof(uint) * ifrm->width * ifrm->height, PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, 0, 0);

	forks = 0;
	current = 0;

	while (TRUE)
	{
		if (current == threads)
		{
			wait(NULL);
			current--;
		}

		if (forks == ifrm->height)
		{
			if (current == 0)
				break;
			continue;
		}

		if (fork() == 0)
		{
			mandelbrot_row(IDX(sm, ifrm->width, forks), width, iterations, min, delta);
			exit(EXIT_SUCCESS);
		}

		current++;
		forks++;
	}

	memcpy(ifrm->frame, sm, sizeof(uint) * ifrm->width * ifrm->height);
	munmap(sm, sizeof(uint) * ifrm->width * ifrm->height);
}
