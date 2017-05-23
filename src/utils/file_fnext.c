#include "file.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INDEX_MAX 1000000
#define BUFFER_OFFSET 8
#define FNAME_TEMPLATE "%s_%i"

BOOL fnext(char * * const out, char const * const fname)
{
	uint i;
	uint n;
	uint len;

	len = strlen(fname);

	out[0] = (char*) malloc(sizeof(char) * (len + BUFFER_OFFSET));

	for (i = 0; i < INDEX_MAX; i++)
	{
		n = sprintf(out[0], FNAME_TEMPLATE, fname, i);

		out[0][n] = NULL_TERM;

		if (fexists(out[0]))
			continue;

		
		return TRUE;
	}

	return FALSE;
}