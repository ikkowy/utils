#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../sha1.h"

int main() {
    const char* data = "";
    size_t size = strlen(data);
    uint8_t hash[SHA1_HASH_SIZE];
    char hex[SHA1_HEX_STRING_SIZE];

    sha1((const uint8_t*) data, size, hash);
    sha1_hex_string(hash, hex);
    printf("%s\n", hex);

    return EXIT_SUCCESS;
}
