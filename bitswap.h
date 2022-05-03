#ifndef BITSWAP_H
#define BITSWAP_H

#include <stdint.h>

static inline uint16_t bswap16(uint16_t x) {
#if defined(__clang__) || defined(__GNUC__)
    return __builtin_bswap16(x);
#elif defined(_MSC_VER)
    return _byteswap_ushort(x);
#else
    return ((0x00ff & x) << 8) | ((0xff00 & x) >> 8);
#endif
}

static inline uint32_t bswap32(uint32_t x) {
#if defined(__clang__) || defined(__GNUC__)
    return __builtin_bswap32(x);
#elif defined(_MSC_VER)
    return _byteswap_ulong(x);
#else
    return ((0x000000ff & x) << 24) | ((0x0000ff00 & x) << 8) |
           ((0x00ff0000 & x) >> 8) | ((0xff000000 & x) >> 24);
#endif
}

static inline uint64_t bswap64(uint64_t x) {
#if defined(__clang__) || defined(__GNUC__)
    return __builtin_bswap64(x);
#elif defined(_MSC_VER)
    return _byteswap_uint64(x);
#else
    return ((0x00000000000000ffull & x) << 56) |
           ((0x000000000000ff00ull & x) << 40) |
           ((0x0000000000ff0000ull & x) << 24) |
           ((0x00000000ff000000ull & x) << 8) |
           ((0x000000ff00000000ull & x) >> 8) |
           ((0x0000ff0000000000ull & x) >> 24) |
           ((0x00ff000000000000ull & x) >> 40) |
           ((0xff00000000000000ull & x) >> 56);
#endif
}

#endif /* BITSWAP_H */
