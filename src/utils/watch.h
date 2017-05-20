#ifndef __P_UTILS_WATCH_H
#define __P_UTILS_WATCH_H

typedef struct
{
	double time;
} watch;

void wstart(watch * const);
void wstop(watch * const);

#endif
