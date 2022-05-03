#include <stdio.h>
#include <stdlib.h>

#include "../byteorder.h"

int main() {
    printf("is_big_endian(): %s\n", is_big_endian() ? "true" : "false");
    printf("is_little_endian(): %s\n", is_little_endian() ? "true" : "false");
    return EXIT_SUCCESS;
}
