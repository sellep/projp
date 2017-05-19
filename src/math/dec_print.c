#include "dec.h"

#include <stdio.h>

void dec_print(dec const * const a)
{
	uint i;

	if (ISNEG(a))
	{
		printf("-");
	}

	printf("%u.", a->intg);

	for (i = 0; i < DEC_LEN; i++)
	{
		printf("[%u]", a->decs[i]);
	}
}
