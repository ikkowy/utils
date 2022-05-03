#ifndef BITROT_H
#define BITROT_H

#include <stdint.h>

#if defined(__GNUC__) && defined(__x86_64__)
#include <x86intrin.h>
#elif defined(_MSC_VER)
#include <intrin.h>
#endif

static inline uint8_t rotl8(uint8_t x, uint8_t n) {
#if defined(__clang__)
    return __builtin_rotateleft8(x, n);
#elif defined(__GNUC__) && defined(__x86_64__)
    return __rolb(x, n);
#elif defined(_MSC_VER)
    return _rotl8(x, n);
#else
    return (x << (n % 8)) | (x >> (8 - (n % 8)));
#endif
}

static inline uint16_t rotl16(uint16_t x, uint8_t n) {
#if defined(__clang__)
    return __builtin_rotateleft16(x, n);
#elif defined(__GNUC__) && defined(__x86_64__)
    return __rolw(x, n);
#elif defined(_MSC_VER)
    return _rotl16(x, n);
#else
    return (x << (n % 16)) | (x >> (16 - (n % 16)));
#endif
}

static inline uint32_t rotl32(uint32_t x, uint8_t n) {
#if defined(__clang__)
    return __builtin_rotateleft32(x, n);
#elif defined(__GNUC__) && defined(__x86_64__)
    return __rold(x, n);
#elif defined(_MSC_VER)
    return _rotl(x, n);
#else
    return (x << (n % 32)) | (x >> (32 - (n % 32)));
#endif
}

static inline uint64_t rotl64(uint64_t x, uint8_t n) {
#if defined(__clang__)
    return __builtin_rotateleft64(x, n);
#elif defined(__GNUC__) && defined(__x86_64__)
    return __rolq(x, n);
#elif defined(_MSC_VER)
    return _rotl64(x, n);
#else
    return (x << (n % 64)) | (x >> (64 - (n % 64)));
#endif
}

static inline uint8_t rotr8(uint8_t x, uint8_t n) {
#if defined(__clang__)
    return __builtin_rotateright8(x, n);
#elif defined(__GNUC__) && defined(__x86_64__)
    return __rorb(x, n);
#elif defined(_MSC_VER)
    return _rotr8(x, n);
#else
    return (x >> (n % 8)) | (x << (8 - (n % 8)));
#endif
}

static inline uint16_t rotr16(uint16_t x, uint8_t n) {
#if defined(__clang__)
    return __builtin_rotateright16(x, n);
#elif defined(__GNUC__) && defined(__x86_64__)
    return __rorw(x, n);
#elif defined(_MSC_VER)
    return _rotr16(x, n);
#else
    return (x >> (n % 16)) | (x << (16 - (n % 16)));
#endif
}

static inline uint32_t rotr32(uint32_t x, uint8_t n) {
#if defined(__clang__)
    return __builtin_rotateright32(x, n);
#elif defined(__GNUC__) && defined(__x86_64__)
    return __rord(x, n);
#elif defined(_MSC_VER)
    return _rotr(x, n);
#else
    return (x >> (n % 32)) | (x << (32 - (n % 32)));
#endif
}

static inline uint64_t rotr64(uint64_t x, uint8_t n) {
#if defined(__clang__)
    return __builtin_rotateright64(x, n);
#elif defined(__GNUC__) && defined(__x86_64__)
    return __rorq(x, n);
#elif defined(_MSC_VER)
    return _rotr64(x, n);
#else
    return (x >> (n % 64)) | (x << (64 - (n % 64)));
#endif
}

#endif /* BITROT_H */
