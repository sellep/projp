#include "kara.h"

extern inline void kara_add(uint * const, uint const * const, uint const, uint const * const, uint const);
extern inline void fast_kara_sub(uint * const, uint const, uint const * const, uint const, uint const * const, uint const);
extern inline void kara_combine(uint * const, uint const, uint const * const, uint const);

void fast_kara_mul(uint * const c , uint const * const a, uint const * const b, uint const * const buf, uint const len)
{
	if (len <= KARA_THRESHOLD)
		return dec_umul(c, a, b, len);

//arrange
	uint hlen = len / 2;
	uint llen = len - hlen;

	uint *ah = a;
	uint *bh = b;
	uint *al = a + hlen;
	uint *bl = b + hlen;

	uint z2len = 2 * (llen + 1);

	uint *as = buf;
	uint *bs = as + (llen + 1);

	uint *z0 = c;
	uint *z1 = c + (2 * hlen);
	uint *z2 = bs + (llen + 1);

	uint *nbuf = z2 + z2len;

//sum
	kara_add(as, ah, hlen, al, llen);
	kara_add(bs, bh, hlen, bl, llen);

//divide
	fast_kara_mul(z0, a, b, nbuf, hlen);
	fast_kara_mul(z1, a + hlen, b + hlen, nbuf, llen);
	fast_kara_mul(z2, as, bs, nbuf, llen + 1);

//combine
	fast_kara_sub(z2, z2len, z0, 2 * hlen, z1, 2 * llen);
	kara_combine(c, (len + len) - llen - z2len, z2, z2len);
}