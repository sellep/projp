
#include "test.h"

#include <stdlib.h>

#define ITERATIONS 100000

int main()
{
	srand(time(NULL));

	int tres;

	printf("dec_uadd_commutative ");
	tres = dec_uadd_commutative(ITERATIONS);

	printf("dec_add_zero ");
	tres = dec_add_zero(ITERATIONS);

	printf("dec_add_commutative ");
	tres = dec_add_commutative(ITERATIONS);

	printf("dec_sub_zero ");
	tres = dec_sub_zero(ITERATIONS);

	printf("dec_sub_commutative ");
	tres = dec_sub_commutative(ITERATIONS);

	return tres;
}
