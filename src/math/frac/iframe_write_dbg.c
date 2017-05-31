#include "fractal.h"

BOOL iframe_write_dbg(iframe const * const ifrm, char const * const fname)
{
	FILE *f;
	size_t i;
	size_t x;
	size_t y; 

	f = fopen(fname, "w");

	if (!f)
		return FALSE;

	for (y = 0; y < ifrm->height; y++)
	{
		for (x = 0; x < ifrm->width; x++)
		{
			i = y * ifrm->width + x;
			fprintf(f, "[%u]", ifrm->frame[i]);
		}

		fprintf(f, "\n");
	}

	fclose(f);
	return TRUE;
}
