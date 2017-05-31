#include "kara.h"

#include <string.h>

extern inline void kara_mul(uint * const, uint const * const, uint const * const, uint const);

void kara(dec * const c, dec * const a, dec * const b)
{
	uint r[2 * (DEC_LEN + 1)];
	uint asign;
	uint bsign;

	if (ISPOS(a))
	{
		asign = POSITIVE;
	}
	else
	{
		MKPOS(a);
		asign = NEGATIVE;
	}

	if (ISPOS(b))
	{
		bsign = POSITIVE;
	}
	else
	{
		MKPOS(b);
		bsign = NEGATIVE;
	}

	kara_mul(r, a, b, DEC_LEN + 1);
	memcpy(c, r + 1, sizeof(dec));

	if (asign == POSITIVE)
	{
		if (bsign == NEGATIVE)
		{
			MKNEG(b);

			if (!dec_iszero(c))
			{
				MKNEG(c);
			}
		}
	}
	else
	{
		MKNEG(a);

		if (bsign == NEGATIVE)
		{
			MKNEG(b);
		}
		else if (!dec_iszero(c))
		{
			MKNEG(c);
		}
	}
}
