#include "file.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int fwrite_all(void const * const buf, uint len, char const * const fname)
{
	FILE *fptr;
	char *fbuf;

	fptr = fopen(fname, "w");
	if (!fptr)
		return FOPEN_FAILED;

	fbuf = (char*) malloc(len + 1);
	memcpy(fbuf, buf, len);
	fbuf[len] = NULL_TERM;

	fputs(fbuf, fptr);

	free(fbuf);

	if (fclose(fptr) != 0)
		return FCLOSE_FAILED;
	return OK;
}
