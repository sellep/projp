#include "media.h"

#include <stdio.h>

BOOL palette_write(palette const * const plt, char const * const path)
{
	FILE *f;
	size_t i;

	f = fopen(path, "w");

	if (!f)
	{
		fprintf(stderr, "unable to open %s\n", path);
		return FALSE;	
	}

	fprintf(f, "%zu\n", plt->len);

	for (i = 0; i < plt->len; i++)
	{
		fprintf(f, "[%zu,%zu,%zu]\n", plt->clr[i].r, plt->clr[i].g, plt->clr[i].b);
	}

	fclose(f);
	return TRUE;
}
