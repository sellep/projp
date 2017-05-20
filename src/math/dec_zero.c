#include "dec.h"

void dec_zero(dec * const a)
{
	memset(a, 0, sizeof(dec));
	MKPOS(a);
}
