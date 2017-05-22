#include "kara.h"

#include <stdlib.h>

void kara_add(uint * const c, uint const * const a, uint const alen, uint const * const b, uint const blen)
{
    int ia;
    ulong tmp;
    ulong carry = 0;

    if (alen == blen)
    {
        for (ia = alen - 1; ia >= 0; ia--)
        {
            tmp = (ulong)a[ia] + b[ia] + carry;
            carry = OVERFLOW(tmp);
            c[ia + 1] = VALUE(tmp);
        }

        c[0] = carry;
    }
    else
    {
        for (ia = alen - 1; ia >= 0; ia--)
        {
            tmp = (ulong)a[ia] + b[ia + 1] + carry;
            carry = OVERFLOW(tmp);
            c[ia + 2] = VALUE(tmp);
        }

        tmp = (ulong)b[0] + carry;
        c[1] = VALUE(tmp);
        c[0] = OVERFLOW(tmp);
    }
}