#include "dec.h"

void dec_add(dec * const c, dec const * const a, dec const * const b)
{
	if (ISPOS(a))
	{
		if (ISPOS(b))
		{
			dec_uadd(c, a, b);
			MKPOS(c);
			return;
		}

		if (dec_ucmp(a, b) == BELOW)
		{
			dec_usub(c, b, a);
			MKNEG(c);
			return;
		}

		dec_usub(c, a, b);
		MKPOS(c);
		return;
	}

	if (ISNEG(b))
	{
		dec_uadd(c, a, b);
		MKNEG(c);
		return;
	}

	if (dec_ucmp(a, b) == ABOVE)
	{
		dec_usub(c, a, b);
		MKNEG(c);
		return;
	}

	dec_usub(c, b, a);
	MKPOS(c);
}
