#include "media.h"

#define ROUND(d)((int)(d+0.5))

BOOL palette_ipol(palette * const p, color const * const c, uint const bas)
{
	uint i;
	uint j;
	uint p;
	uint pad;
	uint lpad;

	double rd;
	double gd;
	double bd;

	p->plt = (color*)malloc(sizeof(color) * p->len);

	pad = ROUND((p->len - bas) / ((double)bas - 1));

	for (i = 0, j = 0; i < bas - 1; i++)
	{
		p->plt[j].r = c[i].r;
		p->plt[j].g = c[i].g;
		p->plt[j].b = c[i].b;

		rd = ((double)c[i + 1].r - c[i].r) / (pad + 1);
		gd = ((double)c[i + 1].g - c[i].g) / (pad + 1);
		bd = ((double)c[i + 1].b - c[i].b) / (pad + 1);

		for (j = j + 1, p = 0; p < pad; j++, p++)
		{
			p->plt[j].r = ()(p->plt[j - 1].r + rd);
		}
	}
}