#include "dec.h"

#include <stdio.h>

void dec_sprint(FILE *f, dec const * const a)
{
	uint i;

	if (ISNEG(a))
	{
		sprintf(f, "-");
	}

	sprintf(f, "%u.", a->intg);

	for (i = 0; i < DEC_LEN; i++)
	{
		sprintf(f, "[%u]", a->decs[i]);
	}
}
