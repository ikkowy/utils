#include <string.h>

#include "bitrot.h"
#include "byteorder.h"
#include "sha1.h"

static const uint32_t k[] = {
    0x5a827999,
    0x6ed9eba1,
    0x8f1bbcdc,
    0xca62c1d6
};

void sha1_transform(uint32_t state[5], const uint8_t block[SHA1_BLOCK_SIZE]) {
    uint32_t W[80];
    uint32_t a, b, c, d, e, T;
    int t = 0;

    for (t = 0; t < 16; t++) {
        W[t] = (block[t * 4] << 24) | (block[t * 4 + 1] << 16) | (block[t * 4 + 2] << 8) | (block[t * 4 + 3]);
    }

    for (; t < 80; t++) {
        W[t] = rotl32(W[t - 3] ^ W[t - 8] ^ W[t - 14] ^ W[t - 16], 1);
    }

    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];

    for (t = 0; t < 80; t++) {
        T = rotl32(a, 5) + e + k[t / 20] + W[t];

        if (t <= 19) {
            T += (b & c) | (~b & d);
        } else if (t <= 39) {
            T += b ^ c ^ d;
        } else if (t <= 59) {
            T += (b & c) | (b & d) | (c & d);
        } else {
            T += b ^ c ^ d;
        }

        e = d;
        d = c;
        c = rotl32(b, 30);
        b = a;
        a = T;
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
}

void sha1_init(sha1_ctx* ctx) {
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xefcdab89;
    ctx->state[2] = 0x98badcfe;
    ctx->state[3] = 0x10325476;
    ctx->state[4] = 0xc3d2e1f0;

    ctx->bit_size = 0;
    ctx->buffer_size = 0;
}

void sha1_update(sha1_ctx* ctx, const uint8_t* data, size_t size) {
    if (size >= SHA1_BLOCK_SIZE - ctx->buffer_size) {
        memcpy(ctx->buffer + ctx->buffer_size, data, SHA1_BLOCK_SIZE - ctx->buffer_size);
        sha1_transform(ctx->state, ctx->buffer);
        size -= SHA1_BLOCK_SIZE - ctx->buffer_size;

        while (size >= SHA1_BLOCK_SIZE) {
            sha1_transform(ctx->state, data);
            data += SHA1_BLOCK_SIZE;
            size -= SHA1_BLOCK_SIZE;
        }

        memcpy(ctx->buffer, data, size);
        ctx->buffer_size = size;
    } else {
        memcpy(ctx->buffer + ctx->buffer_size, data, size);
        ctx->buffer_size += size;
    }

    ctx->bit_size += size * 8;
}

void sha1_final(sha1_ctx* ctx, uint8_t* hash) {
    if (ctx->buffer_size > SHA1_BLOCK_SIZE - 8) {
        memset(ctx->buffer + ctx->buffer_size, 0, SHA1_BLOCK_SIZE - ctx->buffer_size);
        ctx->buffer[ctx->buffer_size] = 0x80;
        sha1_transform(ctx->state, ctx->buffer);
        ctx->buffer_size = 0;
    }

    memset(ctx->buffer + ctx->buffer_size, 0, SHA1_BLOCK_SIZE - ctx->buffer_size);
    ctx->buffer[ctx->buffer_size] = 0x80;
    ctx->bit_size = tobe64(ctx->bit_size);
    memcpy(ctx->buffer + (SHA1_BLOCK_SIZE - 8), &ctx->bit_size, 8);
    sha1_transform(ctx->state, ctx->buffer);

    ((uint32_t*) hash)[0] = frombe32(ctx->state[0]);
    ((uint32_t*) hash)[1] = frombe32(ctx->state[1]);
    ((uint32_t*) hash)[2] = frombe32(ctx->state[2]);
    ((uint32_t*) hash)[3] = frombe32(ctx->state[3]);
    ((uint32_t*) hash)[4] = frombe32(ctx->state[4]);
}

void sha1(const uint8_t* data, size_t size, uint8_t* hash) {
    sha1_ctx ctx;
    sha1_init(&ctx);
    sha1_update(&ctx, data, size);
    sha1_final(&ctx, hash);
}

void sha1_hex_string(uint8_t* hash, char* hex) {
    const char digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                               'a', 'b', 'c', 'd', 'e', 'f' };
    for (int i = 0; i < 20; i++) {
        hex[2 * i] = digits[hash[i] >> 4];
        hex[2 * i + 1] = digits[hash[i] & 0x0f];
    }
    hex[40] = '\0';
}
