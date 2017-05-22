#include "dec.h"

void dec_imul(dec * const c, dec const * const a, uint const i)
{
	int i;
	ulong tmp;
	CARRY carry = 0;

	for (i = DEC_LEN - 1; i >= 0; i--)
	{
		tmp = (ulong)a->decs[i] * i + carry;
		carry = OVERFLOW(tmp);
		c->decs[i] = VALUE(tmp);
	}

	c->intg = a->intg * i + carry;
}
