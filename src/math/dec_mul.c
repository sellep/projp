#include "dec.h"

#include <string.h>

void dec_mul(dec * const c, dec * const a, dec * const b)
{
	uint r[2 * (DEC_LEN + 1)];
	ushort asign = POSITIVE;
	ushort bsign = POSITIVE;

	if (ISNEG(a))
	{
		MKPOS(a);
		asign = NEGATIVE;
	}

	if (ISNEG(b))
	{
		MKPOS(b);
		bsign = NEGATIVE;
	}
	//printf("MUL a/b: %u/%u\n", ((uint*) a)[0], ((uint*) b)[0]);
	dec_umul(r, (uint*) a, (uint*) b, DEC_LEN + 1);
	//printf("MUL: %u\n", r[1]);
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
