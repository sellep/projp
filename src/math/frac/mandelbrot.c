#include "fractal.h"

void mandelbrot(uint * const iframe, uint const iterations, uint const width, uint const height, dec const * const x0, dec const * const y0, dec const * const dx, dec const * const dy)
{
	uint x;
	uint y;

	dec cr;
	dec ci;
	dec zr;
	dec zi;

	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			dec_imul(cr, dx, x);
			dec_add(cr, x0, cr);
			dec_imul(ci, dy, y);
			dec_add(ci, y0, ci);

			
		}
	}
}