#include "test.h"

int dec_square_mul_equal()
{
	dec a, b, c;

	watch *wsquare, *wmul, *wcmp, *wall;
	int cmp;

	winit(&wsquare);
	winit(&wmul);
	winit(&wcmp);
	winit(&wall);

	wstart(wall);

	uint i;
	for (i = 0; i < ITERATIONS; i++)
	{
		dec_rand(&a);

		wstart(wsquare);
		dec_square(&b, &a);
		wstop(wsquare);

		wstart(wmul);
		dec_mul(&c, &a, &a);
		wstop(wmul);

		wstart(wcmp);
		cmp = dec_cmp(&b, &c);
		wstop(wcmp);

		if (cmp != EQUAL)
			break;
	}

	wstop(wall);

	if (i == ITERATIONS)
	{
		printf("success\n");
		printf("overall time %u, average %f\n", wall->time, (double) wall->time / ITERATIONS);
		printf("overall square time %u, average %f\n", wsquare->time, (double) wsquare->time / ITERATIONS);
		printf("overall mul time %u, average %f\n", wmul->time, (double) wmul->time / ITERATIONS);
		printf("overall cmp time %u, average %f\n", wcmp->time, (double) wcmp->time / ITERATIONS);
	}
	else
	{
		printf("failure\n");
		printf("a: ");
		dec_print(&a);
		printf("\nb: ");
		dec_print(&b);
		printf("\nc: ");
		dec_print(&c);
		printf("\n");
	}

	wfree(wsquare);
	wfree(wmul);
	wfree(wcmp);
	wfree(wall);

	return i == ITERATIONS ? SUCCESS : FAILURE;
}