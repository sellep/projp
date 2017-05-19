#include "dec.h"

void dec_rsub(dec * const c, dec const * const a, dec const * const b)
{
	int i;
	uint val;
	uint sub;
	ulong tmp;
	CARRY carry = 0;

	for (i = DEC_LEN - 1; i >= 0; i--)
	{
		tmp = b->decs[i] + carry;
		val = a->decs[i];

		carry = OVERFLOW(tmp);
		sub = VALUE(tmp);

		if (sub > val)
		{
			c->decs[i] = (VALUE_MAX - sub) + val + 1;
			carry++;
		}
		else
		{
			c->decs[i] = val - sub;
		}
	}

	c->intg = a->intg - b->intg - carry;
}
