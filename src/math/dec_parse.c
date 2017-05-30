#include "dec.h"

#include "../utils/file.h"

#include <stdio.h>

BOOL str_index_of(size_t * const out, char const * const str, size_t const start, char const c)
{
	size_t i = 0;

	while (TRUE)
	{
		if (str[start + i] == c)
		{
			*out = start + i;
			return TRUE;
		}

		if (str[start + i] == NULL_TERM)
			return FALSE;
		if (str[start + i] == EOF)
			return FALSE;

		i++;
	}
}

BOOL dec_parse(dec * const d, char * const line)
{
	size_t i = 0, j, x;

	dec_zero(d);

	if (line[0] == '-')
	{
		MKNEG(d);
		i = 1;
	}

	if (!str_index_of(&j, line, i, '.'))
	{
		d->intg = atoi(line + i);
		return TRUE;
	}

	line[j] = NULL_TERM;
	d->intg = atoi(line + i);

	for (x = 0; x < DEC_LEN; x++)
	{
		i = j + 1;

		if (line[i] == EOF)
			return TRUE;
		if (line[i] == NULL_TERM)
			return TRUE;
		if (line[i] == '\n')
			return TRUE;

		if (line[i] != '[')
			return FALSE;

		i++;

		if (!str_index_of(&j, line, i, ']'))
		{
			fprintf(stderr, "missing closing bracket\n");
			return FALSE;
		}

		line[j] = NULL_TERM;

		d->decs[x] = (uint) strtoul(line + i, NULL, 0);
	}

	i = j + 1;

	if (line[i] == EOF)
		return TRUE;
	if (line[i] == NULL_TERM)
		return TRUE;
	if (line[i] == '\n')
		return TRUE;

	return FALSE;
}
