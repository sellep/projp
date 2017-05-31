#include "dec.h"

#include <string.h>

void dec_square(dec * const c, dec * const a)
{
	uint rc[2 * (sizeof(dec) / sizeof(uint))];
	ushort asign = POSITIVE;
	int i, j;
	ulong tmp;
	CARRY carry;

	uint *ra = (uint*) a;

	memset(rc, 0, sizeof(dec) * 2);

	if (ISNEG(a))
	{
		MKPOS(a);
		asign = NEGATIVE;
	}

	for (i = DEC_LEN + 1; i >= 0; i--)
	{
		carry = 0;

		for (j = DEC_LEN + 1; j >= 0; j--)
		{
			tmp = (ulong)ra[i] * ra[j] + carry + rc[i + j + 1];
			rc[i + j + 1] = VALUE(tmp);
			carry = OVERFLOW(tmp);
		}

		rc[i] += carry;
	}

	memcpy(c, rc + 1, sizeof(dec));

	if (asign == NEGATIVE)
	{
		MKNEG(a);
	}
}
