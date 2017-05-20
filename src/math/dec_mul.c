#include "dec.h"

#include <string.h>

void dec_mul(dec * const c, dec * const a, dec * const b)
{
	uint r[2 * (DEC_LEN + 1)];
	ushort asign;
	ushort bsign;

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

	dec_umul(r, (uint*) a, (uint*) b, DEC_LEN + 1);

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
