#include "pack.h"
#include "utils.h"

SFP_UTYPE pack_sfp(unpacked_t us, int es, int fs)
{
    SFP_UTYPE sign = us.sign ? SFP_MSB : SFP_ZERO;

    SFP_STYPE ubexp = us.exp + util_sfp_bias(es);
    if (ubexp > (SFP_STYPE)util_sfp_exp_max(es)) {
        return (sign | util_sfp_max(es, fs));
    } else if (ubexp <= 0) {
        return SFP_ZERO;
    }

    SFP_UTYPE exp = LHIDE(LSHIFT(ubexp, SFP_WIDTH - (1 + es)), 1);
    SFP_UTYPE frac = LMASK(RSHIFT(us.frac, 1 + es), (1 + es + fs));

    return (sign | exp | frac);
}

float pack_float(unpacked_t us)
{
    uint32_t fsign = us.sign ? FLOAT_MSB : FLOAT_ZERO;
    uint32_t fexp = LSHIFT(us.exp + 127, 23) & RSHIFT(FLOAT_MASK, 1);
    uint32_t ffrac = RSHIFT(us.frac, 1 + 8);

    union {
        float f;
        uint32_t u;
    } un;

    un.u = fsign | fexp | ffrac;
    return un.f;
}

double pack_double(unpacked_t us)
{
    uint64_t fsign = us.sign ? DOUBLE_MSB : DOUBLE_ZERO;
    uint64_t fexp = LSHIFT((uint64_t)(us.exp + 1023), 52) & RSHIFT(DOUBLE_MASK, 1);
    uint64_t ffrac = RSHIFT(LSHIFT((uint64_t)us.frac, 32), 1 + 11);

    union {
        double d;
        uint64_t u;
    } un;

    un.u = fsign | fexp | ffrac;
    return un.d;
}

unpacked_t unpack_sfp(SFP_UTYPE s, int es, int fs)
{
    unpacked_t us;
    bool sign = util_sfp_sign(s);
    SFP_STYPE exp = util_sfp_exp(s, es, fs);
    SFP_UTYPE frac = util_sfp_frac(s, es, fs);

    us.sign = sign;
    us.exp = exp;
    us.frac = frac;

    return us;
}

unpacked_t unpack_float(float n)
{
    unpacked_t us;

    union {
        float f;
        uint32_t u;
    } un;

    un.f = n;

    us.sign = RSHIFT(un.u, 31);
    us.exp = (RSHIFT(un.u, 23) & 0xFF) - 127;
    us.frac = LSHIFT(un.u, 1 + 8);

    return us;
}

unpacked_t unpack_double(double n)
{
    unpacked_t us;

    union {
        double d;
        uint64_t u;
    } un;

    un.d = n;

    us.sign = RSHIFT(un.u, 63);
    us.exp = (RSHIFT(un.u, 52) & 0x7FF) - 1023;
    us.frac = RSHIFT(LSHIFT(un.u, 12), 64 - SFP_WIDTH);

    return us;
}
