#include <assert.h>
#include <stdlib.h>

#include "../bitrot.h"

uint8_t ROTL8(uint8_t x, uint8_t n) { return (x << (n % 8)) | (x >> (8 - (n % 8))); }
uint16_t ROTL16(uint16_t x, uint8_t n) { return (x << (n % 16)) | (x >> (16 - (n % 16))); }
uint32_t ROTL32(uint32_t x, uint8_t n) { return (x << (n % 32)) | (x >> (32 - (n % 32))); }
uint64_t ROTL64(uint64_t x, uint8_t n) { return (x << (n % 64)) | (x >> (64 - (n % 64))); }

uint8_t ROTR8(uint8_t x, uint8_t n) { return (x >> (n % 8)) | (x << (8 - (n % 8))); }
uint16_t ROTR16(uint16_t x, uint8_t n) { return (x >> (n % 16)) | (x << (16 - (n % 16))); }
uint32_t ROTR32(uint32_t x, uint8_t n) { return (x >> (n % 32)) | (x << (32 - (n % 32))); }
uint64_t ROTR64(uint64_t x, uint8_t n) { return (x >> (n % 64)) | (x << (64 - (n % 64))); }

int main() {
    for (int n = 0; n < 256; n++) assert(rotl8(1, n) == ROTL8((uint8_t) 1, n));
    for (int n = 0; n < 256; n++) assert(rotl16(1, n) == ROTL16((uint16_t) 1, n));
    for (int n = 0; n < 256; n++) assert(rotl32(1, n) == ROTL32((uint32_t) 1, n));
    for (int n = 0; n < 256; n++) assert(rotl64(1, n) == ROTL64((uint64_t) 1, n));

    for (int n = 0; n < 256; n++) assert(rotr8(1, n) == ROTR8((uint8_t) 1, n));
    for (int n = 0; n < 256; n++) assert(rotr16(1, n) == ROTR16((uint16_t) 1, n));
    for (int n = 0; n < 256; n++) assert(rotr32(1, n) == ROTR32((uint32_t) 1, n));
    for (int n = 0; n < 256; n++) assert(rotr64(1, n) == ROTR64((uint64_t) 1, n));

    return EXIT_SUCCESS;
}
