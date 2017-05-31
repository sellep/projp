#include "test.h"

#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define LOG_TEMPLATE "/tmp/projp_test.log"

FILE* get_log()
{
	FILE *fd;

	fd = fopen(LOG_TEMPLATE, "w");

	return fd;
}

void close_log(FILE const * const f)
{
	
	fclose(f);
}


int main()
{
	srand(time(NULL));

	int tres;

	printf("dec_uadd_commutative ");
	if ((tres = dec_uadd_commutative()) != SUCCESS)
		return FAILURE;

	printf("dec_add_zero ");
	if ((tres = dec_add_zero()) != SUCCESS)
		return FAILURE;

	printf("dec_add_commutative ");
	if ((tres = dec_add_commutative()) != SUCCESS)
		return FAILURE;

	printf("dec_sub_zero ");
	if ((tres = dec_sub_zero()) != SUCCESS)
		return FAILURE;

	printf("dec_sub_commutative ");
	if ((tres = dec_sub_commutative()) != SUCCESS)
		return FAILURE;

	printf("dec_mul_zero ");
	if ((tres = dec_mul_zero()) != SUCCESS)
		return FAILURE;

	printf("dec_mul_commutative ");
	if ((tres = dec_mul_commutative()) != SUCCESS)
		return FAILURE;

	printf("dec_uadd2i_equal ");
	if ((tres = dec_uadd2i_equal()) != SUCCESS)
		return FAILURE;

	printf("dec_imul_idiv_equal ");
	if ((tres = dec_imul_idiv_equal()) != SUCCESS)
		return FAILURE;

	printf("kara_mul_equal ");
	if ((tres = kara_mul_equal()) != SUCCESS)
		return FAILURE;

	printf("kara_perf ");
	if ((tres = kara_perf()) != SUCCESS)
		return FAILURE;

	return tres;
}
