#ifndef __P_TEST_H
#define __P_TEST_H

#define SUCCESS 1
#define FAILURE -1

#include "../src/defs.h"
#include "../src/math/dec.h"
#include "../src/utils/watch.h"

#include <stdio.h>

int dec_add_zero(uint const);
int dec_uadd_commutative(uint const);
int dec_add_commutative(uint const);
int dec_sub_zero(uint const);
int dec_sub_commutative(uint const);
int dec_mul_zero(uint const);
int dec_mul_commutative(uint const);

#endif
