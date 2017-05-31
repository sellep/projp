#include "dec.h"

void dec_imul(dec * const c, dec const * const a, uint const i)
{
	int j;
	ulong tmp;
	CARRY carry = 0;

	for (j = DEC_LEN - 1; j >= 0; j--)
	{
		tmp = (ulong)a->decs[j] * i + carry;
		carry = OVERFLOW(tmp);
		c->decs[j] = VALUE(tmp);
	}


	c->intg = a->intg * i + carry;
	c->sign = a->sign;
}
