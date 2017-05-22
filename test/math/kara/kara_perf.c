#include "../test.h"

int kara_perf()
{
	dec a, b, c, d, e;

	watch *wkara, *wfkara, *wmul, *wcmp, *wall;
	int cmp1;
	int cmp2;

	winit(&wkara);
	winit(&wfkara);
	winit(&wmul);
	winit(&wcmp);
	winit(&wall);

	wstart(wall);

	uint i;
	for (i = 0; i < ITERATIONS; i++)
	{
		dec_rand(&a);
		dec_rand(&b);

		wstart(wmul);
		dec_mul(&c, &a, &b);
		wstop(wmul);

		wstart(wkara);
		kara(&d, &a, &b);
		wstop(wkara);

		wstart(wfkara);
		dec_mul(&e, &a, &b);
		wstop(wfkara);

		wstart(wcmp);
		cmp1 = dec_cmp(&c, &d);
		cmp2 = dec_cmp(&c, &e);
		wstop(wcmp);

		if (cmp1 != EQUAL)
			break;
		if (cmp2 != EQUAL)
			break;
	}

	wstop(wall);

	if (i == ITERATIONS)
	{
		printf("success\n");
		printf("overall time %u, average %f\n", wall->time, (double) wall->time / ITERATIONS);
		printf("overall mul time %u, average %f\n", wmul->time, (double) wmul->time / ITERATIONS);
		printf("overall kara time %u, average %f\n", wkara->time, (double) wkara->time / ITERATIONS);
		printf("overall fast kara time %u, average %f\n", wfkara->time, (double) wfkara->time / ITERATIONS);
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
		printf("\ne: ");
		dec_print(&e);
		printf("\n");
	}

	wfree(wkara);
	wfree(wfkara);
	wfree(wmul);
	wfree(wcmp);
	wfree(wall);

	return i == ITERATIONS ? SUCCESS : FAILURE;
}