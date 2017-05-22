#include "../test.h"

int dec_mul_commutative(uint iter)
{
	dec a, b, c, d;

	watch *wmul, *wcmp, *wall;
	int cmp;

	winit(&wmul);
	winit(&wcmp);
	winit(&wall);

	wstart(wall);

	uint i;
	for (i = 0; i < iter; i++)
	{
		dec_rand(&a);
		dec_rand(&b);

		wstart(wmul);

		dec_mul(&c, &a, &b);
		dec_mul(&d, &b, &a);

		wstop(wmul);

		wstart(wcmp);

		cmp = dec_cmp(&c, &d);

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
