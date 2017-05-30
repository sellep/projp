#include "dec.h"

void dec_idiv(dec * const c, dec * const a, size_t const div)
{
	BOOL isneg = FALSE;
	uint *raw_a;
	uint *raw_c;	
	ssize_t i;
	ulong tmp = 0;

	if (ISNEG(a))
	{
		isneg = TRUE;
		MKPOS(a);
	}

	for (i = 0; i < DEC_LEN + 1; i++)
	{
		tmp = (tmp << DEC_BASE) + raw_a[i];
		raw_c[i] = tmp / div;
		tmp = tmp - ((ulong) raw_c[i] * div);
	}

	if (isneg)
	{
		MKNEG(a);
		MKNEG(c);
	}
}
