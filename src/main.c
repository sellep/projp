#include "defs.h"
#include "math/dec.h"

#include <stdlib.h>
#include <stdio.h>

int main()
{
	srand(time(NULL));

	dec a;
	dec_rand(&a);
	dec_print(&a);

	return 0;
}
