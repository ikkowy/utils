#ifndef BASE64_H
#define BASE64_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

size_t base64_encode(const uint8_t* input, size_t size, char* output);

size_t base64_decode(const char* input, uint8_t* output, bool* error);

#endif /* BASE64_H */
