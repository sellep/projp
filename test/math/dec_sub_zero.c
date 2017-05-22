#include "../test.h"

#include "string.h"

int dec_sub_zero()
{
	dec a, b, c, d;

	watch *wsub, *wcmp, *wall;
	int cmp;

	winit(&wsub);
	winit(&wcmp);
	winit(&wall);

	memset(&d, 0, sizeof(dec));
	MKPOS(&d);

	wstart(wall);

	uint i;
	for (i = 0; i < ITERATIONS; i++)
	{
		dec_rand(&a);
		dec_cpy(&b, &a);

		wstart(wsub);
		dec_sub(&c, &a, &b);
		wstop(wsub);

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
		printf("overall sub time %u, average %f\n", wsub->time, (double) wsub->time / ITERATIONS);
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

	wfree(wsub);
	wfree(wcmp);
	wfree(wall);

	return i == ITERATIONS ? SUCCESS : FAILURE;
}
