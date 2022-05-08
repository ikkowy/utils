#include <stdio.h>
#include <stdlib.h>

#include "../base64.h"

int main() {
    uint8_t output[1024];
    size_t size;
    bool error;

    const char* input = "TMOmbiBsZXJudCBmw7xyIGRpZSBLbGF1c3VyIQ==";

    size = base64_decode(input, output, &error);

    printf("size = %zd\n", size);
    printf("%s\n", (const char*) output);
    printf("%s\n", error ? "error" : "no error");

    return EXIT_SUCCESS;
}
