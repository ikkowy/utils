#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <utils/sha1.h>

#define BUFFER_SIZE 1024

int main() {
    uint8_t buffer[BUFFER_SIZE];
    uint8_t hash[SHA1_HASH_SIZE];
    char hex[SHA1_HEX_STRING_SIZE];
    size_t n;

    sha1_ctx ctx;
    sha1_init(&ctx);

    if (!isatty(STDIN_FILENO)) {
        for (;;) {
            n = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            if (n == 0) break;
            sha1_update(&ctx, buffer, n);
        }
    }

    sha1_final(&ctx, hash);

    sha1_hex_string(hash, hex);

    fputs(hex, stdout);

    return EXIT_SUCCESS;
}
