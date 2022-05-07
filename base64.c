#include "base64.h"

static const uint8_t encode_map[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'
};

size_t base64_encode(const uint8_t* input, size_t size, char* output) {
    size_t n = size / 3;
    size_t m = size % 3;
    size_t i;
    if (input != NULL && output != NULL) {
        for (i = 0; i < n; i++) {
            *(output++) = encode_map[(input[i * 3] & 0xfc) >> 2];
            *(output++) = encode_map[((input[i * 3] & 0x03) << 4) | ((input[i * 3 + 1] & 0xf0) >> 4)];
            *(output++) = encode_map[((input[i * 3 + 1] & 0x0f) << 2) | ((input[i * 3 + 2] & 0xc0) >> 6)];
            *(output++) = encode_map[input[i * 3 + 2] & 0x3f];
        }
        if (m == 2) {
            *(output++) = encode_map[(input[i * 3] & 0xfc) >> 2];
            *(output++) = encode_map[((input[i * 3] & 0x03) << 4) | ((input[i * 3 + 1] & 0xf0) >> 4)];
            *(output++) = encode_map[(input[i * 3 + 1] & 0x0f) << 2];
            *(output++) = '=';
        } else if (m == 1) {
            *(output++) = encode_map[(input[i * 3] & 0xfc) >> 2];
            *(output++) = encode_map[(input[i * 3] & 0x03) << 4];
            *(output++) = '=';
            *(output++) = '=';
        }
        *(output++) = '\0';
    }
    return 4 * ((size + 2) / 3) + 1;
}

#define INV_CHAR -1
#define PAD_CHAR -2
#define NUL_CHAR -3

static int decode_map(char c) {
    if (c >= 'A' && c <= 'Z') return c - 65;
    if (c >= 'a' && c <= 'z') return c - 97 + 26;
    if (c >= '0' && c <= '9') return c - 48 + 52;
    if (c == '+') return 62;
    if (c == '/') return 63;
    if (c == '=') return PAD_CHAR;
    if (c == '\0') return NUL_CHAR;
    return INV_CHAR;
}

size_t base64_decode(const char* input, uint8_t* output, bool* error) {
    size_t i = 0;
    size_t size = 0;
    int s, v;
    bool pad;
    uint8_t b1, b2, b3;
    for (;;) {
        s = i % 4;
        v = decode_map(input[i++]);
        if (v == INV_CHAR) goto error;
        switch (s) {
        case 0:
            if (v == NUL_CHAR) goto done;
            if (v == PAD_CHAR) goto error;
            b1 = v << 2;
            break;
        case 1:
            if (v == NUL_CHAR) goto error;
            if (v == PAD_CHAR) goto error;
            b1 |= (v & 0x30) >> 4;
            b2 = (v & 0x0f) << 4;
            break;
        case 2:
            if (v == NUL_CHAR) goto error;
            pad = (v == PAD_CHAR);
            if (!pad) {
                b2 |= (v & 0x3c) >> 2;
                b3 = (v & 0x03) << 6;
            }
            break;
        case 3:
            if (v == NUL_CHAR) goto error;
            if (pad) {
                if (v != PAD_CHAR) goto error;
                b3 = 0x00;
            } else {
                b3 |= v;
            }
            if (output != NULL) {
                *(output++) = b1;
                *(output++) = b2;
                *(output++) = b3;
            }
            size += 3;
            break;
        }
    }
done:
    if (error != NULL) *error = false;
    return size;
error:
    if (error != NULL) *error = true;
    return 0;
}
