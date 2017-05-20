#include "test.h"

#include <stdlib.h>

#define ITERATIONS 10000

extern int dec_add_zero(uint const);
extern int dec_uadd_commutative(uint const);
extern int dec_add_commutative(uint const);

int main()
{
	int tres;

	printf("dec_uadd_commutative ");
	tres = dec_uadd_commutative(ITERATIONS);

	printf("dec_add_zero ");
	tres = dec_add_zero(ITERATIONS);

	printf("dec_add_commutative ");
	tres = dec_add_commutative(ITERATIONS);

	return tres;
}
