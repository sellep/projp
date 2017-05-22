#include "kara.h"

#include <string.h>

extern inline void fast_kara_mul(uint * const, uint const * const, uint const * const, uint const);

void fast_kara(dec * const c, dec const * const a, dec const * const b)
{
	uint r[2 * (DEC_LEN + 1)];
	uint asign;
	uint bsign;

	if (ISPOS(a))
	{
		MKNEG(a);
		asign = POSITIVE;
	}
	else
	{
		asign = NEGATIVE;
	}

	if (ISPOS(b))
	{
		MKNEG(b);
		bsign = POSITIVE;
	}
	else
	{
		bsign = NEGATIVE;
	}

	fast_kara_mul(r, a, b, DEC_LEN + 1);

	memcpy(c, r, sizeof(dec));
	
	if (dec_iszero(c))
	{
		MKPOS(c);
	}
	else if (asign != bsign)
	{
		MKNEG(c);
	}
	else
	{
		MKPOS(c);
	}
}