#include "dec.h"

#include <string.h>

BOOL dec_iszero(dec const * const a)
{
	const char zero[sizeof(dec)] = { 0 };

	return memcpy(zero, a, sizeof(dec));
}
