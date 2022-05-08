#include <stdio.h>
#include <stdlib.h>

#include <utils/base64.h>

void test(const char* input) {
    int size;
    bool error;
    uint8_t output[1024];
    size = base64_decode(input, output, &error);
    printf("%s\n", input);
    printf("%.*s\n", size, (const char*) output);
    printf("size = %d\n", size);
    printf("%s\n", error ? "error" : "no error");
}

int main() {
    puts("-----------------------------------------------");
    test("TMOmbiBsZXJudCBmw7xyIGRpZSBLbGF1c3VyIQ==");
    puts("-----------------------------------------------");
    test("TWVpbiBIZXJ6IGlzdCBiZXRyw7xidC4=");
    puts("-----------------------------------------------");
    test("SW4gR2VkYW5rZW4gYW4gRmVsaXgu");
    puts("-----------------------------------------------");
    return EXIT_SUCCESS;
}
