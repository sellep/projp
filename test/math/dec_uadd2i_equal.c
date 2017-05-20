#include "../test.h"

int dec_uadd2i_equal()
{
	dec a, b, c;

	watch *wuadd2i, *wuadd, *wall;
	uint intg;

	winit(&wuadd2i);
	winit(&wuadd);
	winit(&wall);

	wstart(wall);

	uint i;
	for (i = 0; i < ITERATIONS; i++)
	{
		dec_rand(&a);
		dec_rand(&b);

		wstart(wuadd2i);
		intg = dec_uadd2i(&a, &b);
		wstop(wuadd2i);

		wstart(wuadd);
		dec_uadd(&c, &a, &b);
		wstop(wuadd);

		if (intg != c.intg)
			break;
	}

	wstop(wall);

	if (i == ITERATIONS)
	{
		printf("success\n");
		printf("overall time %u, average %f\n", wall->time, (double) wall->time / ITERATIONS);
		printf("overall uadd2i time %u, average %f\n", wuadd2i->time, (double) wuadd2i->time / ITERATIONS);
		printf("overall uadd time %u, average %f\n", wuadd->time, (double) wuadd->time / ITERATIONS);
	}
	else
	{
		printf("failure\n");
		printf("a: ");
		dec_print(&a);
		printf("\nb: ");
		dec_print(&b);
		printf("\nintg: %u", intg);
		printf("\nc: ");
		dec_print(&c);
		printf("\n");
	}

	wfree(wuadd2i);
	wfree(wuadd);
	wfree(wall);

	return i == ITERATIONS ? SUCCESS : FAILURE;
}
