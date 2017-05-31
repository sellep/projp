#include "fractal.h"

void mandelbrot(iframe const * const ifrm, dec const * const r_min, dec const * const i_min, cmplx const * const delta)
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

	for (y = 0; y < ifrm->height; y++)
	{
		for (x = 0; x < ifrm->width; x++)
		{
			dec_imul(cr, &delta->r, x);
			dec_add(cr, r_min, cr);
			dec_imul(ci, &delta->i, y);
			dec_add(ci, i_min, ci);

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
				dec_mul(zr2, zr, zr);

				printf("zr: ");
				dec_print(zr);
				printf("\n");

				printf("zr2: ");
				dec_print(zr2);
				printf("\n");

				return;

				dec_mul(zr, zi, zi);
				dec_sub(zr2, zr2, zr);

				i++;
			}
			while (i < ifrm->iterations - 1 && dec_uadd2i(zr2, zi2) < FRAC_THRESHOLD);

			ifrm->frame[y * ifrm->width + x] = i;
		}

	}
}
