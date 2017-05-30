#include "../test.h"

#include <stdlib.h>

int dec_imul_idiv_equal()
{
	dec a, b, c;
	ssize_t div_mul;

	watch *wimul, *widiv, *wcmp, *wall;
	int cmp;

	winit(&wimul);
	winit(&widiv);
	winit(&wcmp);
	winit(&wall);

	wstart(wall);

	uint i;
	for (i = 0; i < ITERATIONS; i++)
	{
		dec_rand(&a);	
		div_mul = rand() % 10;

		wstart(wimul);
		dec_imul(&b, &a, div_mul);
		wstop(wimul);

		wstart(widiv);
		dec_idiv(&c, &b, div_mul);
		wstop(widiv);

		wstart(wcmp);
		cmp = dec_cmp(&a, &c);
		wstop(wcmp);

		if (cmp != EQUAL)
			break;
	}

	wstop(wall);

	if (i == ITERATIONS)
	{
		printf("success\n");
		printf("overall time %u, average %f\n", wall->time, (double) wall->time / ITERATIONS);
		printf("overall imul time %u, average %f\n", wimul->time, (double) wimul->time / ITERATIONS);
		printf("overall idiv time %u, average %f\n", widiv->time, (double) widiv->time / ITERATIONS);
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
		printf("\ndiv: %zu\n", div_mul);
	}

	wfree(wimul);
	wfree(widiv);
	wfree(wcmp);
	wfree(wall);

	return i == ITERATIONS ? SUCCESS : FAILURE;
}
