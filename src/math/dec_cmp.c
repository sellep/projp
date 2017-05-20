#include "dec.h"

int dec_cmp(dec const * const a, dec const * const b)
{
	uint i;

	if (ISPOS(a))
	{
		if (ISNEG(b))
			return ABOVE;

		return dec_ucmp(a, b);
	}

	if (ISPOS(b))
		return BELOW;

	return dec_ucmp(b, a);
}
