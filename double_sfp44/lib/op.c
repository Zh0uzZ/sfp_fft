#include "op.h"

unpacked_t add(unpacked_t a, unpacked_t b, bool sign)
{
    unpacked_t r;

    SFP_LUTYPE afrac = HIDDEN_BIT(a.frac);
    SFP_LUTYPE bfrac = HIDDEN_BIT(b.frac);
    SFP_LUTYPE frac;

    if (a.exp > b.exp)
    {
        r.exp = a.exp;
        bfrac = RSHIFT(bfrac, a.exp - b.exp);
    }
    else
    {
        r.exp = b.exp;
        afrac = RSHIFT(afrac, b.exp - a.exp);
    }
    afrac = LSB_EXPAND_MASK(afrac);
    bfrac = LSB_EXPAND_MASK(bfrac);
    frac = afrac + bfrac;
    if (RSHIFT(frac, SFP_WIDTH) != 0)
    {
        r.exp++;
        frac = RSHIFT(frac, 1);
    }

    r.sign = sign;
    r.frac = LSHIFT(frac, 1);

    return r;
}

unpacked_t sub(unpacked_t a, unpacked_t b, bool sign)
{
    unpacked_t r;

    SFP_UTYPE afrac = HIDDEN_BIT(a.frac);
    SFP_UTYPE bfrac = HIDDEN_BIT(b.frac);
    SFP_UTYPE frac;

    if (a.exp > b.exp || (a.exp == b.exp && a.frac > b.frac))
    {
        r.exp = a.exp;
        bfrac = RSHIFT(bfrac, a.exp - b.exp);
        afrac = LSB_EXPAND_MASK(afrac);
        bfrac = LSB_EXPAND_MASK(bfrac);
        frac = afrac - bfrac;
    }
    else
    {
        sign = !sign;
        r.exp = b.exp;
        afrac = RSHIFT(afrac, b.exp - a.exp);
        afrac = LSB_EXPAND_MASK(afrac);
        bfrac = LSB_EXPAND_MASK(bfrac);
        frac = bfrac - afrac;
    }

    r.sign = sign;
    r.exp -= CLZ(frac);
    r.frac = LSHIFT(frac, CLZ(frac) + 1);

    return r;
}

unpacked_t op_add(unpacked_t a, unpacked_t b)
{
    if (a.sign == b.sign)
    {
        return add(a, b, a.sign);
    }
    else
    {
        return sub(a, b, a.sign);
    }
}

unpacked_t op_sub(unpacked_t a, unpacked_t b)
{
    if (a.sign == b.sign)
    {
        return sub(a, b, a.sign);
    }
    else
    {
        return add(a, b, a.sign);
    }
}

unpacked_t op_mul(unpacked_t a, unpacked_t b)
{
    unpacked_t r;

    SFP_LUTYPE afrac = HIDDEN_BIT(a.frac);
    SFP_LUTYPE bfrac = HIDDEN_BIT(b.frac);
    SFP_UTYPE frac = RSHIFT(afrac * bfrac, SFP_WIDTH);
    SFP_STYPE exp = a.exp + b.exp + 1;

    if ((frac & SFP_MSB) == 0)
    {
        exp--;
        frac = LSHIFT(frac, 1);
    }

    r.sign = a.sign ^ b.sign;
    r.exp = exp;
    r.frac = LSHIFT(frac, 1);

    return r;
}
