#include "dec.h"

#include <string.h>

void dec_mul(dec * const c, dec * const a, dec * const b)
{
	//printf("%ua * %ub = ", a->sign, b->sign);

	uint r[2 * (DEC_LEN + 1)];
	BOOL aneg = FALSE;
	BOOL bneg = FALSE;

	if (ISNEG(a))
	{
		MKPOS(a);
		aneg = TRUE;
	}

	if (ISNEG(b))
	{
		MKPOS(b);
		bneg = TRUE;
	}

	dec_umul(r, (uint*) a, (uint*) b, DEC_LEN + 1);
	memcpy(c, r + 1, sizeof(dec));

	if (aneg)
	{
		MKNEG(a);

		if (bneg)
		{
			MKNEG(b);
		}
		else if (!dec_iszero(c))
		{
			MKNEG(c);
		}
	}
	else
	{
		if (bneg)
		{
			MKNEG(b);

			if (!dec_iszero(c))
			{
				MKNEG(c);
			}
		}
	}

	//printf("%ua * %ub = %uc\n", a->sign, b->sign, c->sign);
}
