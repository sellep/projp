#include "dec.h"

#include "string.h"

void dec_cpy(dec * const c, dec const * const a)
{
	memcpy(c, a, sizeof(dec));
}
