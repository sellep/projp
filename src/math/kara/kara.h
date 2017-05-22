#ifndef __P_MATH_KARATSUBA_H
#define __P_MATH_KARATSUBA_H

#include "../dec.h"

#define KARA_THRESHOLD 5

inline void fast_kara(dec * const, dec const * const, dec const * const);
inline void kara(dec * const, dec const * const, dec const * const);

#endif