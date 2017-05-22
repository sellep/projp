#include <stdio.h>

long fsize(FILE * const fptr)
{
	long size;

	fseek(fptr, 0, SEEK_END);
	size = ftell(fptr);
	rewind(fptr);

	return size;
}