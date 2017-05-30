#include "media.h"
#include "../utils/file.h"

#include <stdio.h>
#include <stdlib.h>

BOOL palette_read_line_comma(size_t * const end, char const * const line, size_t const start)
{
	size_t i;

	for (i = 0 ;; i++)
	{
		if (line[start + i] == EOF)
			return FALSE;

		if (line[start + i] == NULL_TERM)
			return FALSE;

		if (line[start + i] == ',')
		{
			*end = start + i;
			return TRUE;
		}
	}	
}

BOOL palette_read(palette * const plt, char const * const fname)
{
	FILE *f;
	char *line = NULL;
	size_t line_len, i, cma, cmb;
	ssize_t read;

	f = fopen(fname, "r");

	if (!f)
	{
		fprintf(stderr, "unable to open %s\n", fname);
		return FALSE;
	}

	if ((read = getline(&line, &line_len, f)) == -1)
	{
		fprintf(stderr, "empty palette file %s\n", fname);
		goto error;
	}

	plt->len = atoi(line);
	plt->clr = (color*) malloc(sizeof(color) * plt->len);

	for (i = 0; i < plt->len; i++)
	{
		if ((read = getline(&line, &line_len, f)) == -1)
		{
			fprintf(stderr, "inconsistent palette file %s\n", fname);
			goto full_error;
		}

		if (line[0] != '[' || line[read - 2] != ']')
		{
			fprintf(stderr, "inconsistent line %zu in palette file %s\n", i + 1, fname);
			goto full_error;
		}

		cma = 1;

		if (!palette_read_line_comma(&cmb, line, cma))
		{
			fprintf(stderr, "inconsistent line %zu in palette file %s\n", i + 1, fname);
			goto full_error;
		}

		line[cmb] = NULL_TERM;
		plt->clr[i].r = (byte) atoi(line + 1);

		cmb++;

		if (!palette_read_line_comma(&cma, line, cmb))
		{
			fprintf(stderr, "inconsistent line %zu in palette file %s\n", i + 1, fname);
			goto full_error;
		}

		line[cma] = NULL_TERM;	
		plt->clr[i].g = (byte) atoi(line + cmb);

		line[read - 2] = NULL_TERM;
		plt->clr[i].b = (byte) atoi(line + cma + 1);
	}


	free(line);
	fclose(f);
	return TRUE;

full_error:
	free(plt->clr);
error:
	free(line);
	fclose(f);
	return FALSE;
}
