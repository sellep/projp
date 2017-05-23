#ifndef __P_MATH_FRACTAL_H
#define __P_MATH_FRACTAL_H

#include "../dec.h"
#include "../complex/complex.h"

#define FRAC_THRESHOLD 4

typedef struct
{
	uint width;
	uint height;
	uint iterations;
	uint *frame;
} iframe;

void mandelbrot(iframe const * const, dec const * const, dec const * const, complex const * const);

void iframe_writenext(iframe const * const, char const * const);

#endif
