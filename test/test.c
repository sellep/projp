
#include "test.h"

#include <stdlib.h>

int main()
{
	srand(time(NULL));

	int tres;

	printf("dec_uadd_commutative ");
	tres = dec_uadd_commutative();

	printf("dec_add_zero ");
	tres = dec_add_zero();

	printf("dec_add_commutative ");
	tres = dec_add_commutative();

	printf("dec_sub_zero ");
	tres = dec_sub_zero();

	printf("dec_sub_commutative ");
	tres = dec_sub_commutative();

	printf("dec_mul_zero ");
	tres = dec_mul_zero();

	printf("dec_mul_commutative ");
	tres = dec_mul_commutative();

	printf("kara_mul ");
	tres = kara_mul();

	return tres;
}
