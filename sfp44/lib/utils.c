#include "utils.h"

bool util_is_zero(SFP_UTYPE s, int es)
{
    return (LHIDE(LMASK(s, es + 1), 1) == SFP_ZERO);
}

bool util_is_neg(SFP_UTYPE s)
{
    return ((SFP_STYPE)s < 0);
}

SFP_UTYPE util_sfp_bias(int es)
{
    return (SFP_UTYPE)POW2(es - 1);
}

int util_sfp_nbits(int es, int fs)
{
    return (1 + es + fs);
}

bool util_sfp_sign(SFP_UTYPE s)
{
    return util_is_neg(s);
}

SFP_STYPE util_sfp_exp(SFP_UTYPE s, int es, int fs)
{
    SFP_STYPE exp = RSHIFT(LHIDE(LMASK(s, 1 + es), 1), SFP_WIDTH - (1 + es));
    return (exp - util_sfp_bias(es));
}

SFP_UTYPE util_sfp_exp_max(int es)
{
    return (SFP_UTYPE)(POW2(es) - 1);
}

SFP_UTYPE util_sfp_frac(SFP_UTYPE s, int es, int fs)
{
    SFP_UTYPE frac = LSHIFT(s, (1 + es));
    return frac;
}

SFP_UTYPE util_sfp_max(int es, int fs)
{
    return LMASK(SFP_MAX, (1 + es + fs));
}

SFP_UTYPE util_sfp_min(int es)
{
    return LSHIFT(SFP_MIN, SFP_WIDTH - (es + 1));
}

SFP_UTYPE util_sfp_neg(SFP_UTYPE s)
{
    return (s ^ SFP_MSB);
}
