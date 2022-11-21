#include "sfp.hh"
#include "utils.h"
#include "pack.h"
#include "op.h"

#include <cstdio>
#include <cmath>

#include <iostream>
using namespace std;

using std::cout;
using std::endl;

SFP::SFP(SFP_UTYPE bits, int es, int fs) : bits(bits),
                                           es(es),
                                           fs(fs)
{
}

SFP::SFP(int es, int fs) : SFP::SFP(SFP_ZERO, es, fs)
{
}

bool SFP::isZero() const
{
    return util_is_zero(bits, es);
}

bool SFP::isNeg() const
{
    return util_is_neg(bits);
}

int SFP::nBits() const
{
    return util_sfp_nbits(es, fs);
}

int SFP::bias() const
{
    return util_sfp_bias(es);
}

bool SFP::sign() const
{
    return util_sfp_sign(bits);
}

SFP_STYPE SFP::exp() const
{
    return util_sfp_exp(bits, es, fs);
}

SFP_UTYPE SFP::frac() const
{
    return util_sfp_frac(bits, es, fs);
}

SFP SFP::zero() const
{
    return SFP(SFP_ZERO, es, fs);
}

SFP SFP::absMax() const
{
    return SFP(util_sfp_max(es, fs), es, fs);
}

SFP SFP::absMin() const
{
    return SFP(util_sfp_min(es), es, fs);
}

SFP SFP::max() const
{
    return absMax();
}

SFP SFP::min() const
{
    return absMax().neg();
}

SFP SFP::neg() const
{
    return SFP(util_sfp_neg(bits), es, fs);
}

SFP SFP::abs() const
{
    return (isNeg() ? neg() : *this);
}

SFP SFP::prev() const
{
    if (isZero())
    {
        return absMin().neg();
    }
    else if (*this == min())
    {
        return min();
    }

    SFP_UTYPE prevbits = isNeg() ? getBits() + 1 : getBits() - 1;
    return SFP(LSHIFT(prevbits, SFP_WIDTH - nBits()), es, fs);
}

SFP SFP::next() const
{
    if (isZero())
    {
        return absMin();
    }
    else if (*this == max())
    {
        return max();
    }

    SFP_UTYPE nextbits = isNeg() ? getBits() - 1 : getBits() + 1;
    return SFP(LSHIFT(nextbits, SFP_WIDTH - nBits()), es, fs);
}

SFP SFP::add(const SFP &s) const
{
    if (isZero())
    {
        return s;
    }
    else if (s.isZero())
    {
        return *this;
    }
    else if (neg().eq(s))
    {
        return zero();
    }

    unpacked_t ua = unpack_sfp(bits, es, fs);
    unpacked_t ub = unpack_sfp(s.bits, s.es, s.fs);
    unpacked_t ur = op_add(ua, ub);

    return SFP(pack_sfp(ur, es, fs), es, fs);
}

SFP SFP::sub(const SFP &s) const
{
    if (isZero())
    {
        return s.neg();
    }
    else if (s.isZero())
    {
        return *this;
    }
    else if (eq(s))
    {
        return zero();
    }

    unpacked_t ua = unpack_sfp(bits, es, fs);
    unpacked_t ub = unpack_sfp(s.bits, s.es, s.fs);
    unpacked_t ur = op_sub(ua, ub);

    return SFP(pack_sfp(ur, es, fs), es, fs);
}
SFP& SFP::easy_reciprocal(SFP s)
{
    SFP_UTYPE exp;
    int a;
    unpacked_t ua = unpack_sfp(s.bits, s.es, s.fs);
    exp = ua.exp;
    ua.exp = -exp;
    ua.frac = 0;
    bits = pack_sfp(ua, s.es, s.fs);
    return *this;
}
SFP SFP::mul(const SFP &s) const
{
    if (isZero() || s.isZero())
    {
        return zero();
    }

    unpacked_t ua = unpack_sfp(bits, es, fs);
    unpacked_t ub = unpack_sfp(s.bits, s.es, s.fs);
    unpacked_t ur = op_mul(ua, ub);

    return SFP(pack_sfp(ur, es, fs), es, fs);
}

bool SFP::eq(const SFP &s) const
{
    if (isZero() && s.isZero())
    {
        return true;
    }
    return (bits == s.bits && es == s.es && fs == s.fs);
}

SFP &SFP::set(SFP s)
{
    bits = pack_sfp(unpack_sfp(s.bits, s.es, s.fs), es, fs);
    return *this;
}

SFP &SFP::set(float n)
{
    switch (fpclassify(n))
    {
    case FP_INFINITE:
    case FP_NAN:
        bits = SFP_MAX;
        break;
    case FP_ZERO:
    case FP_SUBNORMAL:
        bits = SFP_ZERO;
        break;
    default:
        bits = pack_sfp(unpack_float(n), es, fs);
    }
    return *this;
}

SFP &SFP::set(double n)
{
    switch (fpclassify(n))
    {
    case FP_INFINITE:
    case FP_NAN:
        bits = SFP_MAX;
        break;
    case FP_ZERO:
    case FP_SUBNORMAL:
        bits = SFP_ZERO;
        break;
    default:
        bits = pack_sfp(unpack_double(n), es, fs);
    }
    return *this;
}

SFP &SFP::resizeTo(int es, int fs)
{
    if (isZero())
    {
        this->bits = SFP_ZERO;
    }
    else
    {
        this->bits = pack_sfp(unpack_sfp(this->bits, this->es, this->fs), es, fs);
    }
    this->es = es;
    this->fs = fs;

    return *this;
}

float SFP::getFloat() const
{
    if (isZero())
    {
        return 0.0;
    }

    return pack_float(unpack_sfp(bits, es, fs));
}

double SFP::getDouble() const
{
    if (isZero())
    {
        return 0.0;
    }

    return pack_double(unpack_sfp(bits, es, fs));
}

SFP &SFP::setBits(SFP_UTYPE s)
{
    bits = LSHIFT(s, SFP_WIDTH - nBits());
    return *this;
}

SFP_UTYPE SFP::getBits() const
{
    return RSHIFT(bits, SFP_WIDTH - nBits());
}

void SFP::print() const
{
    SFP s = abs();

    printf("sfp<%d,%d> ", es, fs);

    for (int i = SFP_WIDTH - 1; i >= SFP_WIDTH - nBits(); i--)
    {
        printf("%d", RSHIFT(bits, i) & 1);
    }

    printf(" -> ");
    printf(isNeg() ? "-" : "+");

    for (int i = SFP_WIDTH - 2; i >= SFP_WIDTH - nBits(); i--)
    {
        printf("%d", RSHIFT(s.bits, i) & 1);
        if (i != SFP_WIDTH - nBits() && (i == SFP_WIDTH - 1 - s.es))
        {
            printf(" ");
        }
    }

    printf(" hex = %03X    ", getBits());
    printf(" dec = %g", getFloat());

    printf("\n");
}
void SFP::printbits() const
{
    SFP s = abs();

    // printf("sfp<%d,%d> ", es, fs);
    printf("9'b");
    for (int i = SFP_WIDTH - 1; i >= SFP_WIDTH - nBits(); i--)
    {
        printf("%d", RSHIFT(bits, i) & 1);
    }
}

SFP operator+(const SFP &a, const SFP &b)
{
    return a.add(b);
}

SFP operator-(const SFP &a, const SFP &b)
{
    return a.sub(b);
}

SFP operator*(const SFP &a, const SFP &b)
{
    return a.mul(b);
}

SFP operator-(const SFP &a)
{
    return a.neg();
}

bool operator==(const SFP &a, const SFP &b)
{
    return a.eq(b);
}
