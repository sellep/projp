#include "defs.h"
#include "math/dec.h"

#include <stdio.h>

int main()
{
	dec a, b;
	dec_print(&a);
	dec_print(&b);

	printf("\n%i\n", dec_cmp(&a, &b));

	return 0;
}
