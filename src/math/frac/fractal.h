#ifndef __P_MATH_FRACTAL_H
#define __P_MATH_FRACTAL_H

#include "../dec.h"
#include "../cmplx.h"
#include "../../project.h"
#include "../../media/media.h"

#define FRAC_THRESHOLD 4

typedef struct
{
	ssize_t width;
	ssize_t height;
	size_t iterations;
	uint *frame;
} iframe;

void iframe_init(iframe * const, project const * const);
void iframe_free(iframe * const);
BOOL iframe_map(color * const, iframe const * const, palette const * const);
BOOL iframe_writenext(iframe const * const, char const * const);
BOOL iframe_write_dbg(iframe const * const, char const * const);

void mandelbrot_row(uint * const, ssize_t const, ssize_t const, size_t const, cmplx const * const, cmplx const * const);
void mandelbrot_cc(iframe * const, cmplx const * const, cmplx const * const, ssize_t const);
void mandelbrot(iframe const * const, dec const * const, dec const * const, cmplx const * const);

#if CUDA

#define IDXX()(blockDim.x * blockIdx.x + threadIdx.x)
#define IDXY()(blockDim.y * blockIdx.y + threadIdx.y)

__global__ void g_mandelbrot_simple(uint*, ssize_t, ssize_t, size_t, void*, void*);

#endif

#endif
