#include "fractal.h"

BOOL iframe_map(color * const buf, iframe const * const ifrm, palette const * const plt)
{
	ssize_t x;
	ssize_t y;
	size_t idx;
	color c;
	uint ival;

	for (y = 0; y < ifrm->height; y++)
	{
		for (x = 0; x < ifrm->width; x++)
		{
			idx = y * ifrm->width + x;
			ival = ifrm->frame[idx];
			
			if (ival >= plt->len)
				return FALSE;

			c = plt->clr[ival];

			buf[idx] = c;
		}
	}

	return TRUE;
}
