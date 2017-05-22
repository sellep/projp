#ifndef __P_TEST_H
#define __P_TEST_H

#define SUCCESS 1
#define FAILURE -1

#include "../src/defs.h"
#include "../src/utils/watch.h"
#include "../src/math/dec.h"
#include "../src/math/kara/kara.h"

#include <stdio.h>

#define ITERATIONS 100000

int dec_add_zero();
int dec_uadd_commutative();
int dec_add_commutative();
int dec_sub_zero();
int dec_sub_commutative();
int dec_mul_zero();
int dec_mul_commutative();
int kara_mul();

#endif
