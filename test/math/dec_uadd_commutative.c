#include "../test.h"

int dec_uadd_commutative(uint iter)
{
	dec a, b, c, d;

	watch wadd, wcmp, wall;
	int cmp;

	wstart(&wall);

	uint i;
	for (i = 0; i < iter; i++)
	{
		dec_rand(&a);
		dec_rand(&b);

		MKPOS(&a);
		MKPOS(&b);

		wstart(&wadd);

		dec_uadd(&c, &a, &b);
		dec_uadd(&d, &b, &a);

		wstop(&wadd);

		wstart(&wcmp);

		cmp = dec_cmp(&c, &d);

		wstop(&wcmp);

		if (cmp != EQUAL)
			break;
	}

	wstop(&wall);


	if (i == iter)
	{
		printf("success\n");
		printf("overall time %f, average %f\n", wall.time, wall.time / iter);
		printf("overall add time %f, average %f\n", wadd.time, wadd.time / iter);
		printf("overall cmp time %f, average %f\n", wcmp.time, wcmp.time / iter);
		return SUCCESS;
	}

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
	return FAILURE;
}
