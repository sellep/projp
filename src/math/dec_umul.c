#include "dec.h"

#include <string.h>

void dec_umul(uint * const c, uint const * const a, uint const * const b, uint const len)
{
	int i, j;
	ulong tmp;
	CARRY carry;

	memset(c, 0, sizeof(uint) * len * 2);

	for (i = len - 1; i >= 0; i--)
	{
		carry = 0;

		for (j = len - 1; j >= 0; j--)
		{
			tmp = (ulong)a[i] * b[j] + carry + c[i + j + 1];
			c[i + j + 1] = VALUE(tmp);
			carry = OVERFLOW(tmp);
		}

		j = i;

		while (TRUE)
		{
			tmp = (ulong)c[j] + carry;
			c[j] = VALUE(tmp);
			carry = OVERFLOW(tmp);

			if (!carry)
				break;

			printf("overflow detected!\n");
			j--;
		}
	}
}
