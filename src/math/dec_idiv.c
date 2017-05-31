#include "dec.h"

void dec_idiv(dec * const c, dec * const a, size_t const div)
{
	ssize_t i;
	ulong tmp = 0;

	tmp = a->intg;
	c->intg = tmp / div;
	tmp = tmp - (c->intg * div);

	for (i = 0; i < DEC_LEN; i++)
	{
		tmp = (tmp << DEC_BASE) + a->decs[i];
		c->decs[i] = tmp / div;
		tmp = tmp - ((ulong) c->decs[i] * div);
	}

	c->sign = a->sign;
}
