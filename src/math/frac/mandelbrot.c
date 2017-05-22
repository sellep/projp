#include "fractal.h"

#define IDX(x,y,w)(w*y+x)

void mandelbrot(uint * const iframe, uint const iterations, uint const width, uint const height, dec const * const x0, dec const * const y0, complex const * const delta)
{
	uint x;
	uint y;
	uint i;

	dec d[6];
	dec *cr = d;
	dec *ci = d + 1;
	dec *zr = d + 2;
	dec *zi = d + 3;
	dec *;

	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			dec_imul(cr, dx, x);
			dec_add(cr, x0, cr);
			dec_imul(ci, dy, y);
			dec_add(ci, y0, ci);

			i = VALUE_MAX;

			//set z and z2 to 0?

			do
			{
				/*
				zr = zr2 + cr;
				zi = zi2 + ci;

				zr2 = zr * zr - zi * zi;
				zi2 = 2 * zr * zi;
				*/

				i++;
			}
			while (i < iterations && dec_uadd2i(&zr2, &zi2) < FRAC_THRESHOLD);
			
			iframe[IDX(x, y, width)] = i;
		}
	}
}