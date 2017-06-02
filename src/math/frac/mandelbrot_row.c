#include "fractal.h"

void mandelbrot_row(uint * const frame, ssize_t const width, ssize_t const y, size_t const iterations, cmplx const * const min, cmplx const * const delta)
{
	uint x;
	uint i;

	dec d[6];
	dec *cr = d;
	dec *ci = d + 1;
	dec *zr = d + 2;
	dec *zi = d + 3;
	dec *zr2 = d + 4;
	dec *zi2 = d + 5;

	for (x = 0; x < width; x++)
	{
		dec_imul(cr, &delta->r, x);
		dec_add(cr, &min->r, cr);
		dec_imul(ci, &delta->i, y);
		dec_add(ci, &min->i, ci);

		i = VALUE_MAX;

		//set zr2 und zi2 to 0
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
			dec_square(zr2, zr);
			dec_square(zr, zi);
			dec_sub(zr2, zr2, zr);

			i++;
		}
		while (i < iterations - 1 && dec_uadd2i(zr2, zi2) < FRAC_THRESHOLD);

		frame[x] = i;
}