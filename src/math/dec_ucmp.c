#include "dec.h"

int dec_ucmp(dec const * const a, dec const * const b)
{
	uint i;

	if (a->intg > b->intg)
		return ABOVE;

	if (a->intg < b->intg)
		return BELOW;

	for (i = 0; i < DEC_LEN; i++)
	{
		if (a->decs[i] > b->decs[i])
			return ABOVE;
		if (a->decs[i] < b->decs[i])
			return BELOW;
	}

	return EQUAL;
}
