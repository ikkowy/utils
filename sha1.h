#ifndef SHA1_H
#define SHA1_H

#include <stddef.h>
#include <stdint.h>

#define SHA1_HASH_SIZE 20

#define SHA1_HEX_STRING_SIZE 41

#define SHA1_BLOCK_SIZE 64

typedef struct {
    uint32_t state[5];
    uint64_t bit_size;
    uint8_t buffer[SHA1_BLOCK_SIZE];
    unsigned int buffer_size;
} sha1_ctx;

void sha1_transform(uint32_t state[5], const uint8_t block[SHA1_BLOCK_SIZE]);

void sha1_init(sha1_ctx* ctx);

void sha1_update(sha1_ctx* ctx, const uint8_t* data, size_t size);

void sha1_final(sha1_ctx* ctx, uint8_t* hash);

void sha1(const uint8_t* data, size_t size, uint8_t* hash);

void sha1_hex_string(uint8_t* hash, char* hex);

#endif /* SHA1_H */
