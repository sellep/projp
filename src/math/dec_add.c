#include "dec.h"

void dec_add(dec * const c, dec const * const a, dec const * const b)
{
	if (ISPOS(a))
	{
		if (ISPOS(b))
		{
			dec_radd(c, a, b);
			MKPOS(c);
			return;
		}

		if (dec_cmp(a, b) == BELOW)
		{
			dec_rsub(c, b, a);
			MKNEG(c);
			return;
		}

		dec_rsub(c, a, b);
		MKPOS(c);
		return;
	}

	if (ISNEG(b))
	{
		dec_radd(c, a, b);
		MKNEG(c);
		return;
	}

	if (dec_cmp(a, b) == BELOW)
	{
		dec_rsub(c, a, b);
		MKNEG(c);
		return;
	}

	dec_rsub(c, b, a);
	MKPOS(c);
}
