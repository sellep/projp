#include "watch.h"

#include <stdlib.h>
#include <sys/time.h>

typedef struct
{
	ulong time;
	struct timeval start;
} internal_watch;

#define CAST(w)((internal_watch*)(w))

void winit(watch * * const w)
{
	w[0] = (watch*) malloc(sizeof(internal_watch));
	w[0]->time = 0;
}

void wstart(watch * const w)
{
	internal_watch *iw = CAST(w);
	gettimeofday(&iw->start, NULL);
}

void wstop(watch * const w)
{
	internal_watch *iw = CAST(w);
	struct timeval end;

	gettimeofday(&end, NULL);

	iw->time += 1000 * (end.tv_sec - iw->start.tv_sec) + (end.tv_usec - iw->start.tv_usec) / 1000;
}

void wfree(watch * const w)
{
	free(w);
}
