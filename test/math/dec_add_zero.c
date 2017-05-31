#include "../test.h"

#include "string.h"

int dec_add_zero()
{
	dec a, b, c, d;

	watch *wadd, *wcmp, *wall;
	int cmp;

	memset(&d, 0, sizeof(dec));

	winit(&wadd);
	winit(&wcmp);
	winit(&wall);

	wstart(wall);

	uint i;
	for (i = 0; i < ITERATIONS; i++)
	{
		dec_rand(&a);
		dec_cpy(&b, &a);

		b.sign = ISPOS(&a) ? NEGATIVE : POSITIVE;

		wstart(wadd);
		dec_add(&c, &a, &b);
		wstop(wadd);

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
		printf("overall add time %u, average %f\n", wadd->time, (double) wadd->time / ITERATIONS);
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

	winit(wadd);
	winit(wcmp);
	winit(wall);

	return i == ITERATIONS ? SUCCESS : FAILURE;
}
