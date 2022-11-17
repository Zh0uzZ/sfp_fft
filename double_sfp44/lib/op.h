#ifndef __SFP_OP_H
#define __SFP_OP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pack.h"
#include "utils.h"

unpacked_t op_add(unpacked_t a, unpacked_t b);
unpacked_t op_sub(unpacked_t a, unpacked_t b);
unpacked_t op_mul(unpacked_t a, unpacked_t b);

#ifdef __cplusplus
}
#endif

#endif
