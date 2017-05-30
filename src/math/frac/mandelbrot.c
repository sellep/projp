#include "fractal.h"

#define IDX(x,y,w)(w*y+x)

void mandelbrot(iframe const * const req, dec const * const x0, dec const * const y0, cmplx const * const delta)
{
	uint x;
	uint y;
	uint i;

	dec d[6];
	dec *cr = d;
	dec *ci = d + 1;
	dec *zr = d + 2;
	dec *zi = d + 3;
	dec *zr2 = d + 4;
	dec *zi2 = d + 5;

	for (y = 0; y < req->height; y++)
	{
		for (x = 0; x < req->width; x++)
		{
			dec_imul(cr, &delta->r, x);
			dec_add(cr, x0, cr);
			dec_imul(ci, &delta->i, y);
			dec_add(ci, y0, ci);

			i = VALUE_MAX;

			memset(zr2, 0, 2 * sizeof(dec));

			do
			{
				//zr = zr2 + cr;
				dec_add(zr, zr2, cr);

				//zi = zi2 + ci;
				dec_add(zi, zi2, ci);

				//zi2 = 2 * zr * zi;
				dec_mul(zi2, zr, zi);
				dec_imul(zi2, zi2, 2);

				//zr2 = zr * zr - zi * zi;
				dec_mul(zr2, zr, zr);
				dec_mul(zr, zi, zi);

				i++;
			}
			while (i < req->iterations && dec_uadd2i(zr2, zi2) < FRAC_THRESHOLD);

			req->frame[IDX(x, y, req->width)] = i;
		}

	}
}
