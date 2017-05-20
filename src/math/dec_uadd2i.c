#include "dec.h"

ushort dec_uadd2i(dec const * const a, dec const * const b)
{
	int i;
	CARRY carry = 0;

	for (i = DEC_LEN - 1; i >= 0; i--)
	{
		carry = OVERFLOW((ulong) a->decs[i] + b->decs[i] + carry);
	}

	return a->intg + b->intg + carry;
}
