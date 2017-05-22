#ifndef __P_UTILS_WATCH_H
#define __P_UTILS_WATCH_H

typedef struct
{
	ulong time;
} watch;

void winit(watch * * const);
void wstart(watch * const);
void wstop(watch * const);
void wfree(watch const * const);

#endif
