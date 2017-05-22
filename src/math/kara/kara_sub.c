#include "kara.h"

/*void fast_kara_sub(uint * const z2, uint const z2len, uint const * const z0, uint const z0len, uint const * const z1, uint const z1len)
{
    int i;
    uint val;
    uint sub;
    ulong tmp;
    CARRY carry = 0;

    if (z0len == z1len)
    {
        for (i = z0len - 1; i >= 0; i--)
        {
            val = z2[i + 2];
            tmp = (ulong)z0[i] + z1[i] + carry;
            sub = VALUE(tmp);
            carry = OVERFLOW(tmp);

            if (val >= sub)
            {
                z2[i + 2] = val - sub;
            }
            else
            {
                z2[i + 2] = ((VALUE_MAX - sub) + val) + 1;
                carry++;
            }
        }
    }
    else
    {
        for (i = z0len - 1; i >= 0; i--)
        {
            val = z2[i + 4];
            tmp = (ulong) z0[i] + z1[i + 2] + carry;
            sub = VALUE(tmp);
            carry = OVERFLOW(tmp);

            if (val >= sub)
            {
                z2[i + 4] = val - sub;
            }
            else
            {
                z2[i + 4] = ((VALUE_MAX - sub) + val) + 1;
                carry++;
            }
        }

        val = z2[3];
        tmp = (ulong)z1[1] + carry;
        sub = VALUE(tmp);
        carry = OVERFLOW(tmp);

        if (val >= sub)
        {
            z2[3] = val - sub;
        }
        else
        {
            z2[3] = ((VALUE_MAX - sub) + val) + 1;
            carry++;
        }

        val = z2[2];
        tmp = (ulong)z1[0] + carry;
        sub = VALUE(tmp);
        carry = OVERFLOW(tmp);

        if (val >= sub)
        {
            z2[2] = val - sub;
        }
        else
        {
            z2[2] = ((VALUE_MAX - sub) + val) + 1;
            carry++;
        }
    }

    if (!carry) return;//avoid memory access, is this even possible to get here?

    val = z2[1];

    if (val >= carry)
    {
        z2[1] = val - carry;
    }
    else
    {
        printf("[fast_kara_sub] carry detected, do not remove this code");

        z2[1] = ((VALUE_MAX - carry) + val) + 1;
        z2[0] -= 1;
    }
}*/

void kara_sub(uint * const z2, uint const z2len, uint const * const z0, uint const z0len, uint const * const z1, uint const z1len)
{
    int i;
    uint val;
    uint sub;
    ulong tmp;
    CARRY carry = 0;

    uint off = z2len - z0len;

    if (z0len == z1len)
    {
        for (i = z0len - 1; i >= 0; i--)
        {
            val = z2[off + i];
            tmp = (ulong)z0[i] + z1[i] + carry;
            sub = VALUE(tmp);
            carry = OVERFLOW(tmp);

            if (val >= sub)
            {
                z2[off + i] = val - sub;
            }
            else
            {
                z2[off + i] = ((VALUE_MAX - sub) + val) + 1;
                carry++;
            }
        }

        while (carry)
        {
            val = z2[off + i];

            if (val >= carry)
            {
                z2[off + i] = val - carry;
                break;
            }
            else
            {
                z2[off + i] = ((VALUE_MAX - carry) + val) + 1;
                carry = 1;
            }

            i--;
        }
    }
    else
    {
        for (i = z0len - 1; i >= 0; i--)
        {
            val = z2[off + i];
            tmp = (ulong)z0[i] + z1[i + 2] + carry;
            sub = VALUE(tmp);
            carry = OVERFLOW(tmp);

            if (val >= sub)
            {
                z2[off + i] = val - sub;
            }
            else
            {
                z2[off + i] = ((VALUE_MAX - sub) + val) + 1;
                carry++;
            }
        }

        val = z2[off + i];
        tmp = (ulong)z1[1] + carry;
        sub = VALUE(tmp);
        carry = OVERFLOW(tmp);

        if (val >= sub)
        {
            z2[off + i] = val - sub;
        }
        else
        {
            z2[off + i] = ((VALUE_MAX - sub) + val) + 1;
            carry++;
        }

        i--;

        val = z2[off + i];
        tmp = (ulong)z1[0] + carry;
        sub = VALUE(tmp);
        carry = OVERFLOW(tmp);

        if (val >= sub)
        {
            z2[off + i] = val - sub;
        }
        else
        {
            z2[off + i] = ((VALUE_MAX - sub) + val) + 1;
            carry++;
        }

        i--;

        while (carry)
        {
            val = z2[off + i];

            if (val >= carry)
            {
                z2[off + i] = val - carry;
                break;
            }
            else
            {
                z2[off + i] = ((VALUE_MAX - carry) + val) + 1;
                carry = 1;
            }

            i--;
        }
    }
}