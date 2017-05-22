#include "../test.h"

#include "string.h"

int dec_sub_commutative(uint iter)
{
	dec a, b, c, d;

	watch *wsub, *wcmp, *wall;
	int cmp;

	winit(&wsub);
	winit(&wcmp);
	winit(&wall);

	wstart(wall);

	uint i;
	for (i = 0; i < iter; i++)
	{
		dec_rand(&a);
		dec_rand(&b);

		wstart(wsub);

		dec_sub(&c, &a, &b);
		dec_sub(&d, &a, &c),

		wstop(wsub);

		wstart(wcmp);

		cmp = dec_cmp(&b, &d);

		wstop(wcmp);

		if (cmp != EQUAL)
			break;
	}

	wstop(wall);

	if (i == iter)
	{
		printf("success\n");
		printf("overall time %u, average %f\n", wall->time, (double) wall->time / iter);
		printf("overall sub time %u, average %f\n", wsub->time, (double) wsub->time / iter);
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

	wfree(wsub);
	wfree(wcmp);
	wfree(wall);

	return i == iter ? SUCCESS : FAILURE;
}
