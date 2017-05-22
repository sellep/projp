#include "../test.h"

#include "string.h"

int dec_mul_zero(uint iter)
{
	dec a, b, c;

	watch *wmul, *wcmp, *wall;
	int cmp;

	winit(&wmul);
	winit(&wcmp);
	winit(&wall);

	memset(&b, 0, sizeof(dec));
	MKPOS(&b);

	wstart(wall);

	uint i;
	for (i = 0; i < iter; i++)
	{
		dec_rand(&a);

		wstart(wmul);

		dec_mul(&c, &a, &b);

		wstop(wmul);

		wstart(wcmp);

		cmp = dec_cmp(&b, &c);

		wstop(wcmp);

		if (cmp != EQUAL)
			break;
	}

	wstop(wall);

	if (i == iter)
	{
		printf("success\n");
		printf("overall time %u, average %f\n", wall->time, (double) wall->time / iter);
		printf("overall mul time %u, average %f\n", wmul->time, (double) wmul->time / iter);
		printf("overall cmp time %u, average %f\n", wcmp->time, (double) wcmp->time / iter);
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

	wfree(wmul);
	wfree(wcmp);
	wfree(wall);

	return i == iter ? SUCCESS : FAILURE;
}
