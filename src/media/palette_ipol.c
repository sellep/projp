#include "media.h"

void palette_ipol(palette const * const plt, color const * const c, size_t const bas)
{
	uint i;
	uint b;
	uint pad;
	uint lpad;
	uint div;

	double cr;
	double cg;
	double cb;
	double dr;
	double dg;
	double db;

	pad = (plt->len - 1) / (bas - 1);
	lpad = plt->len - (bas - 2) * (pad + 1) - 2;

	for (i = 0, b = 0; i < plt->len - 1; i++)
	{
		if (i % (pad + 1) == 0)
		{
			plt->clr[i].r = c[b].r;
			plt->clr[i].g = c[b].g;
			plt->clr[i].b = c[b].b;

			cr = c[b].r;
			cg = c[b].g;
			cb = c[b].b;

			div = b + 2== bas ? lpad + 1 : pad + 1;
			dr = (c[b + 1].r - cr) / div;
			dg = (c[b + 1].g - cg) / div;
			db = (c[b + 1].b - cb) / div;

			b++;
		}
		else
		{
			cr += dr;
			cg += dg;
			cb += db;

			plt->clr[i].r = (byte) cr;
			plt->clr[i].g = (byte) cg;
			plt->clr[i].b = (byte) cb;
		}
	}

	plt->clr[plt->len - 1].r = c[bas - 1].r;
	plt->clr[plt->len - 1].g = c[bas - 1].g;
	plt->clr[plt->len - 1].b = c[bas - 1].b;
}
