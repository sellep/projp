#include "../test.h"

int dec_add_commutative(uint iter)
{
	dec a, b, c, d;

	watch *wadd, *wcmp, *wall;
	int cmp;

	winit(&wadd);
	winit(&wcmp);
	winit(&wall);

	wstart(wall);

	uint i;
	for (i = 0; i < iter; i++)
	{
		dec_rand(&a);
		dec_rand(&b);

		wstart(wadd);

		dec_add(&c, &a, &b);
		dec_add(&d, &b, &a);

		wstop(wadd);

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
		printf("overall add time %u, average %f\n", wadd->time, (double) wadd->time / iter);
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

	wfree(wadd);
	wfree(wcmp);
	wfree(wall);

	return i == iter ? SUCCESS : FAILURE;
}
