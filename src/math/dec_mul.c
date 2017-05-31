#include "dec.h"

#include <string.h>

void dec_mul(dec * const c, dec * const a, dec * const b)
{
	uint r[2 * (DEC_LEN + 1)];
	ushort asign;
	ushort bsign;

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

	dec_umul(r, (uint*) a, (uint*) b, DEC_LEN + 1);
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
