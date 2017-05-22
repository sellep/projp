#include "dec.h"

void dec_mul(dec * const c, dec const * const a, dec const * const b)
{
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

	dec_umul((uint*) c, (uint*) a, (uint*) b);

	if (asign != bsign)
	{
		MKNEG(c);
	}
	else
	{
		MKPOS(c);
	}
}