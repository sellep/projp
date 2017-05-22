#ifndef __P_MATH_DECIMAL_H
#define __P_MATH_DECIMAL_H

#include "../defs.h"

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

#define POSITIVE 1
#define NEGATIVE 0
#define ISPOS(d)((d)->sign)
#define ISNEG(d)((d)->sign == NEGATIVE)
#define NEG(d)((d)->sign = 1 - d->sign)
#define MKPOS(d)((d)->sign = POSITIVE)
#define MKNEG(d)((d)->sign = NEGATIVE)

void dec_print(dec const * const);
void dec_rand(dec * const);
inline BOOL dec_iszero(dec const * const);
inline void dec_cpy(dec * const, dec const * const);
inline int dec_ucmp(dec const * const, dec const * const);
inline int dec_cmp(dec const * const, dec const * const);
inline void dec_add(dec * const, dec const * const, dec const * const);
inline void dec_sub(dec * const, dec const * const, dec const * const);
inline void dec_uadd(dec * const, dec const * const, dec const * const);
inline void dec_usub(dec * const, dec const * const, dec const * const);

inline void dec_umul(uint * const, uint const * const, uint const * const, uint const);
inline void dec_mul(dec * const, dec const * const, dec const * const);

#endif
