#include "kara.h"

void kara_combine(uint * const c, uint const coff, uint const * const z2, uint const z2len)
{
    int i;
    ulong tmp;
    CARRY carry = 0;

    for (i = z2len - 1; i >= 0; i--)
    {
        tmp = (ulong)z2[i] + c[coff + i] + carry;
        c[coff + i] = VALUE(tmp);
        carry = OVERFLOW(tmp);
    }

    while (carry)
    {
        tmp = (ulong)c[coff + i] + carry;
        c[coff + i] = VALUE(tmp);
        carry = OVERFLOW(tmp);
        i--;
    }
}