#include "dec.h"

#include <stdio.h>

void dec_fprint(FILE *f, dec const * const a)
{
	uint i;

	if (ISNEG(a))
	{
		fprintf(f, "-");
	}

	fprintf(f, "%u.", a->intg);

	for (i = 0; i < DEC_LEN; i++)
	{
		fprintf(f, "[%u]", a->decs[i]);
	}
}
