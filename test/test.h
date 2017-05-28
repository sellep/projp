#ifndef __P_TEST_H
#define __P_TEST_H

#define SUCCESS 0
#define FAILURE 1

#include "../src/defs.h"
#include "../src/utils/watch.h"
#include "../src/math/dec.h"
#include "../src/math/kara/kara.h"

#include <stdio.h>

#define ITERATIONS 1000000

FILE* get_log();
void close_log(FILE const * const);

int dec_add_zero();
int dec_uadd_commutative();
int dec_add_commutative();
int dec_sub_zero();
int dec_sub_commutative();
int dec_mul_zero();
int dec_mul_commutative();
int dec_uadd2i_equal();
int dec_imul_idiv_equal();
int kara_mul_equal();
int kara_perf();

#endif
