#include "file.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern long fsize(FILE * const);

long fread_all(void * * const buf, char const * const fname)
{
	FILE *fptr;
	long size;

	fptr = fopen(fname, "rb");

	if (!fptr)
		return FOPEN_FAILED;

	size = fsize(fptr);
	buf[0] = malloc(size);

	fread(buf[0], size, 1, fptr);

	fclose(fptr);

	return size;
}
