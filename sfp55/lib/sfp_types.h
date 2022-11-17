#ifndef __SFP_TYPES_H
#define __SFP_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#define SFP_LUTYPE    uint64_t
#define SFP_UTYPE     uint32_t
#define SFP_STYPE     int32_t
#define SFP_WIDTH     32
#define SFP_ZERO      ((SFP_UTYPE)0x00000000)
#define SFP_MAX       ((SFP_UTYPE)0x7FFFFFFF)
#define SFP_MIN       ((SFP_UTYPE)0x00000001)
#define SFP_MSB       ((SFP_UTYPE)0x80000000)
#define SFP_MASK      ((SFP_UTYPE)0xFFFFFFFF)

#ifdef __cplusplus
}
#endif

#endif
