#include "dec.h"

int dec_cmp(dec const * const a, dec const * const b)
{
	uint i;

	if (ISPOS(a))
	{
		if (ISNEG(b))
			return ABOVE;

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
	else
	{
		if (ISPOS(b))
			return BELOW;

		if (a->intg > b->intg)
			return BELOW;

		if (a->intg < b->intg)
			return ABOVE;

		for (i = 0; i < DEC_LEN; i++)
		{
			if (a->decs[i] > b->decs[i])
				return BELOW;
			if (a->decs[i] < b->decs[i])
				return ABOVE;
		}

		return EQUAL;
	}
}
