#include <stdint.h>
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

#define SHA1_RESULT_SIZE 5

#define SHA1_BLOCK_SIZE 64

static void sha1_block_next(const uint8_t* block, uint32_t* h) {
    unsigned int W[80];
    unsigned int t = 0;
    unsigned int a, b, c, d, e, T;

    for (t = 0; t < 16; t++) {
        W[t] = (block[t * 4] << 24) | (block[t * 4 + 1] << 16) | (block[t * 4 + 2] << 8) | (block[t * 4 + 3]);
    }

    for (; t < 80; t++) {
        W[t] = rotl32(W[t - 3] ^ W[t - 8] ^ W[t - 14] ^ W[t - 16], 1);
    }

    a = h[0];
    b = h[1];
    c = h[2];
    d = h[3];
    e = h[4];

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

    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
}

void sha1(const uint8_t* data, size_t size, uint8_t* hash) {
    unsigned char padded_block[SHA1_BLOCK_SIZE];

    uint64_t bit_size = tobe64(size * 8);

    uint32_t* h = (uint32_t*) hash;

    h[0] = 0x67452301;
    h[1] = 0xefcdab89;
    h[2] = 0x98badcfe;
    h[3] = 0x10325476;
    h[4] = 0xc3d2e1f0;

    while (size >= SHA1_BLOCK_SIZE) {
        sha1_block_next(data, h);
        data += SHA1_BLOCK_SIZE;
        size -= SHA1_BLOCK_SIZE;
    }

    if (size > SHA1_BLOCK_SIZE - 8) {
        memset(padded_block, 0, sizeof(padded_block));
        memcpy(padded_block, data, size);
        padded_block[size] = 0x80;
        sha1_block_next(padded_block, h);
        data += size;
        size = 0;
    }

    memset(padded_block, 0, sizeof(padded_block));
    memcpy(padded_block, data, size);
    padded_block[size] = 0x80;
    memcpy(padded_block + SHA1_BLOCK_SIZE - 8, &bit_size, sizeof(bit_size));

    sha1_block_next(padded_block, h);

    h[0] = frombe32(h[0]);
    h[1] = frombe32(h[1]);
    h[2] = frombe32(h[2]);
    h[3] = frombe32(h[3]);
    h[4] = frombe32(h[4]);
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
