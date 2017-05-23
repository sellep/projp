#include "dec.h"

#include <string.h>

BOOL dec_iszero(dec const * const a)
{
	const char zero[sizeof(dec)] = { 0 };

	return !memcmp(zero, a, sizeof(dec));
}
