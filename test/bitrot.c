#include <assert.h>
#include <stdlib.h>

#include "../bitrot.h"

#define ROTL8(x, n) ((x << (n % 8)) | (x >> (8 - (n % 8))))
#define ROTL16(x, n) ((x << (n % 16)) | (x >> (16 - (n % 16))))
#define ROTL32(x, n) ((x << (n % 32)) | (x >> (32 - (n % 32))))
#define ROTL64(x, n) ((x << (n % 64)) | (x >> (64 - (n % 64))))

int main() {
    for (int n = 0; n < 256; n++) assert(rotl8(1, n) == ROTL8((uint8_t) 1, n));
    for (int n = 0; n < 256; n++) assert(rotl16(1, n) == ROTL16((uint16_t) 1, n));
    for (int n = 0; n < 256; n++) assert(rotl32(1, n) == ROTL32((uint32_t) 1, n));
    for (int n = 0; n < 256; n++) assert(rotl64(1, n) == ROTL64((uint64_t) 1, n));
    return EXIT_SUCCESS;
}
