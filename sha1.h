#ifndef SHA1_H
#define SHA1_H

#include <stddef.h>
#include <stdint.h>

#define SHA1_HASH_SIZE 20

#define SHA1_HEX_STRING_SIZE 41

void sha1(const uint8_t* data, size_t size, uint8_t* hash);

void sha1_hex_string(uint8_t* hash, char* hex);

#endif /* SHA1_H */
