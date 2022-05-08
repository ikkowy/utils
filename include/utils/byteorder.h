#ifndef BYTEORDER_H
#define BYTEORDER_H

#include <stdbool.h>

#include "byteswap.h"

static inline bool is_big_endian() {
#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && defined(__ORDER_BIG_ENDIAN__)
  #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    return true;
  #else
    return false;
  #endif
#else
    uint8_t* p = (uint8_t*) &(uint32_t){0xaabbccdd};
    if (p[0] == 0xaa && p[1] == 0xbb && p[2] == 0xcc && p[3] == 0xdd) return true;
    return false;
#endif
}

static inline bool is_little_endian() {
#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && defined(__ORDER_BIG_ENDIAN__)
  #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    return true;
  #else
    return false;
  #endif
#else
    uint8_t* p = (uint8_t*) &(uint32_t){0xaabbccdd};
    if (p[0] == 0xdd && p[1] == 0xcc && p[2] == 0xbb && p[3] == 0xaa) return true;
    return false;
#endif
}

static inline uint16_t tobe16(uint16_t x) {
    if (is_little_endian()) return bswap16(x);
    return x;
}

static inline uint32_t tobe32(uint32_t x) {
    if (is_little_endian()) return bswap32(x);
    return x;
}

static inline uint64_t tobe64(uint64_t x) {
    if (is_little_endian()) return bswap64(x);
    return x;
}

static inline uint16_t tole16(uint16_t x) {
    if (is_big_endian()) return bswap16(x);
    return x;
}

static inline uint32_t tole32(uint32_t x) {
    if (is_big_endian()) return bswap32(x);
    return x;
}

static inline uint64_t tole64(uint64_t x) {
    if (is_big_endian()) return bswap64(x);
    return x;
}

static inline uint16_t frombe16(uint16_t x) {
    if (is_little_endian()) return bswap16(x);
    return x;
}

static inline uint32_t frombe32(uint32_t x) {
    if (is_little_endian()) return bswap32(x);
    return x;
}

static inline uint64_t frombe64(uint64_t x) {
    if (is_little_endian()) return bswap64(x);
    return x;
}

static inline uint16_t fromle16(uint16_t x) {
    if (is_big_endian()) return bswap16(x);
    return x;
}

static inline uint32_t fromle32(uint32_t x) {
    if (is_big_endian()) return bswap32(x);
    return x;
}

static inline uint64_t fromle64(uint64_t x) {
    if (is_big_endian()) return bswap64(x);
    return x;
}

#endif /* BYTEORDER_H */
