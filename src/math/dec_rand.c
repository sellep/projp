#include "dec.h"

#include <stdlib.h>

#define RAND_INTG_MAX 5

void dec_rand(dec * const a)
{
	uint i;
	uint max = RAND_MAX;
	double fac = (double) VALUE_MAX / RAND_MAX;

	a->intg = rand() % RAND_INTG_MAX;
	a->sign = rand() % 2 == 0 ? POSITIVE : NEGATIVE;

	for (i = 0; i < DEC_LEN; i++)
	{
		a->decs[i] = (uint)(fac * rand());
	}
}
