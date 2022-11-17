#ifndef __SFP_PACK_H
#define __SFP_PACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sfp_types.h"

#define FLOAT_ZERO     ((uint32_t)0x00000000)
#define FLOAT_MSB      ((uint32_t)0x80000000)
#define FLOAT_MASK     ((uint32_t)0xFFFFFFFF)

#define DOUBLE_ZERO    ((uint64_t)0x0000000000000000)
#define DOUBLE_MSB     ((uint64_t)0x8000000000000000)
#define DOUBLE_MASK    ((uint64_t)0xFFFFFFFFFFFFFFFF)

typedef struct {
    bool sign;
    SFP_STYPE exp;
    SFP_UTYPE frac;
} unpacked_t;

SFP_UTYPE pack_sfp(unpacked_t us, int es, int fs);
float pack_float(unpacked_t us);
double pack_double(unpacked_t us);

unpacked_t unpack_sfp(SFP_UTYPE s, int es, int fs);
unpacked_t unpack_float(float n);
unpacked_t unpack_double(double n);

#ifdef __cplusplus
}
#endif

#endif
