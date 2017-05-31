#ifndef __P_MATH_DECIMAL_H
#define __P_MATH_DECIMAL_H

#include "../defs.h"

#include <stdio.h>

#define DEC_LEN 31
#define DEC_BASE 32

#define VALUE_MAX 4294967295u
#define VALUE(x)(x & VALUE_MAX)
#define OVERFLOW(x)(x >> DEC_BASE)

typedef struct
{
	ushort sign;
	ushort intg;
	uint decs[DEC_LEN];
} dec;

enum dec_cmp_e
{
	BELOW = -1,
	EQUAL = 0,
	ABOVE = 1
};

typedef uint CARRY;

#define POSITIVE 0
#define NEGATIVE 1
#define ISPOS(d)((d)->sign == POSITIVE)
#define ISNEG(d)((d)->sign == NEGATIVE)
#define MKPOS(d)((d)->sign = POSITIVE)
#define MKNEG(d)((d)->sign = NEGATIVE)

void dec_zero(dec * const);
BOOL dec_parse(dec * const, char * const);
void dec_fprint(FILE *, dec const * const);
void dec_print(dec const * const);
void dec_rand(dec * const);
BOOL dec_iszero(dec const * const);
void dec_cpy(dec * const, dec const * const);
int dec_ucmp(dec const * const, dec const * const);
int dec_cmp(dec const * const, dec const * const);
void dec_add(dec * const, dec const * const, dec const * const);
ushort dec_uadd2i(dec const * const, dec const * const);
void dec_sub(dec * const, dec const * const, dec const * const);
void dec_uadd(dec * const, dec const * const, dec const * const);
void dec_usub(dec * const, dec const * const, dec const * const);

void dec_umul(uint * const, uint const * const, uint const * const, uint const);
void dec_square(dec * const, dec * const);
void dec_mul(dec * const, dec * const, dec * const);
void dec_imul(dec * const, dec const * const, uint const);
void dec_idiv(dec * const, dec * const, size_t const);

#endif
