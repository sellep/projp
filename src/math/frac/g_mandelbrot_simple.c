#if CUDA

__global__ void g_mandelbrot_simple(uint *iframe, ssize_t width, ssize_t height, size_t iterations, void *min, void *delta)
{
	size_t i;
	dec d[6];

	ssize_t x = IDXX();
	if (x >= width)
		return;

	ssize_t y = IDXY();
	if (y >= height)
		return;

	dec *cr = d;
	dec *ci = d + 1;
	dec *zr = d + 2;
	dec *zi = d + 3;
	dec *zr2 = d + 4;
	dec *zi2 = d + 5;

	dec_imul(cr, &(((*cmplx)delta)->r), x);
	dec_add(cr, &(((*cmplx)min)->r), cr);
	dec_imul(ci, &(((*cmplx)delta)->i), y);
	dec_add(ci, &(((*cmplx)min)->i), ci);

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

	iframe[y * width + x] = i;
}

#endif