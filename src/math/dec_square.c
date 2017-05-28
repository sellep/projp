#include "dec.h"

#include <string.h>

void dec_square(dec * const c, dec * const a)
{
	uint rc[2 * (sizeof(dec) / sizeof(uint))];
	int i, j;
	ulong tmp;
	CARRY carry;

	BOOL aneg = FALSE;
	uint *ra = (uint*) a;

	if (ISNEG(a))
	{
		MKPOS(a);
		aneg = TRUE;
	}

	memset(rc, 0, sizeof(dec) * 2);

	for (i = DEC_LEN + 1; i >= 0; i--)
	{
		carry = 0;

		for (j = DEC_LEN + 1; j >= 0; j--)
		{
			tmp = (ulong)ra[i] * ra[j] + carry + rc[i + j + 1];
			rc[i + j + 1] = VALUE(tmp);
			carry = OVERFLOW(tmp);
		}

		j = i;

		while (TRUE)
		{
			tmp = (ulong)rc[j] + carry;
			rc[j] = VALUE(tmp);
			carry = OVERFLOW(tmp);

			if (!carry)
				break;

			printf("overflow detected\n");
			j--;
		}
	}

	memcpy(c, rc + 1, sizeof(dec));

	if (aneg)
	{
		MKNEG(a);
	}
}
