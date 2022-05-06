#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../sha1.h"

int main() {
    const char* data;
    size_t size;
    uint8_t hash[SHA1_HASH_SIZE];
    char hex[SHA1_HEX_STRING_SIZE];

    data = "";
    size = strlen(data);
    sha1((const uint8_t*) data, size, hash);
    sha1_hex_string(hash, hex);
    printf("%s\n", hex);
    assert(strcmp(hex, "da39a3ee5e6b4b0d3255bfef95601890afd80709") == 0);

    data = "abc";
    size = strlen(data);
    sha1((const uint8_t*) data, size, hash);
    sha1_hex_string(hash, hex);
    printf("%s\n", hex);
    assert(strcmp(hex, "a9993e364706816aba3e25717850c26c9cd0d89d") == 0);

    data = "abcdbcdecdefdefgefghfghighijhi";
    size = strlen(data);

    return EXIT_SUCCESS;
}
