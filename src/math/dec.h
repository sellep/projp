#ifndef __P_MATH_DECIMAL_H
#define __P_MATH_DECIMAL_H

#include "../defs.h"

#define DEC_LEN 31

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

#define POSITIVE 1
#define NEGATIVE 0
#define ISPOS(d)(d->sign)
#define ISNEG(d)(d->sign == NEGATIVE)
#define NEG(d)(d->sign = 1 - d->sign)
#define MKPOS(d)(d->sign = POSITIVE)
#define MKNEG(d)(d->sign = NEGATIVE)

void dec_print(dec const * const);
inline int dec_cmp(dec const * const, dec const * const);
inline void dec_add(dec * const, dec const * const, dec const * const);
inline void dec_radd(dec * const, dec const * const, dec const * const);
inline void dec_rsub(dec * const, dec const * const, dec const * const);

#endif
