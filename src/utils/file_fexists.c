#include "file.h"

#include <unistd.h>

BOOL fexists(char const * const fname)
{
	if (access(fname, F_OK) != -1)
		return true;
	return false;
}