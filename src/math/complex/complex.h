#ifndef __P_MATH_COMPLEX_H
#define __P_MATH_COMPLEX_H

#include "../dec.h"

typedef struct
{
	dec r;
	dec i;
} complex;

void complex_square(complex * const, complex const * complex);

#endif