#include "dec.h"

void dec_uadd(dec * const c, dec const * const a, dec const * const b)
{
	int i;
	ulong tmp;
	CARRY carry = 0;

	for (i = DEC_LEN - 1; i >= 0; i--)
	{
		tmp = (ulong) a->decs[i] + b->decs[i] + carry;
		c->decs[i] = VALUE(tmp);
		carry = OVERFLOW(tmp);
	}

	c->intg = a->intg + b->intg + carry;
}
