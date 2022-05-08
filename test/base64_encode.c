#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <utils/base64.h>

#define INPUT_BUFFER_SIZE 1536
#define OUTPUT_BUFFER_SIZE 2049

int main() {
    uint8_t buffer_input[INPUT_BUFFER_SIZE];
    char buffer_output[OUTPUT_BUFFER_SIZE];
    size_t n;

    if (!isatty(STDIN_FILENO)) {
        for (;;) {
            n = read(STDIN_FILENO, buffer_input, INPUT_BUFFER_SIZE);
            if (n == 0) break;
            base64_encode(buffer_input, n, buffer_output);
            fputs(buffer_output, stdout);
        }
    }

    return EXIT_SUCCESS;
}
