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

	printf("dec_uadd2i_equal ");
	tres = dec_uadd2i_equal();

	printf("dec_imul_idiv_equal ");
	tres = dec_imul_idiv_equal();

	printf("kara_mul_equal ");
	tres = kara_mul_equal();

	printf("kara_perf ");
	tres = kara_perf();

	return tres;
}
