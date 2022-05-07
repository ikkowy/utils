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
