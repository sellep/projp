#include "../../test.h"

int kara_mul_equal()
{
	dec a, b, c, d;

	watch *wkara, *wmul, *wcmp, *wall;
	int cmp;

	winit(&wkara);
	winit(&wmul);
	winit(&wcmp);
	winit(&wall);

	wstart(wall);

	uint i;
	for (i = 0; i < ITERATIONS; i++)
	{
		dec_rand(&a);
		dec_rand(&b);

		wstart(wkara);
		kara(&c, &a, &b);
		wstop(wkara);

		wstart(wmul);
		dec_mul(&d, &a, &b);
		wstop(wmul);

		wstart(wcmp);
		cmp = dec_cmp(&c, &d);
		wstop(wcmp);

		if (cmp != EQUAL)
			break;
	}

	wstop(wall);

	if (i == ITERATIONS)
	{
		printf("success\n");
		printf("overall time %u, average %f\n", wall->time, (double) wall->time / ITERATIONS);
		printf("overall kara time %u, average %f\n", wkara->time, (double) wkara->time / ITERATIONS);
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
		printf("\nd: ");
		dec_print(&d);
		printf("\n");
	}

	wfree(wkara);
	wfree(wmul);
	wfree(wcmp);
	wfree(wall);

	return i == ITERATIONS ? SUCCESS : FAILURE;
}
