CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -fsanitize=unreachable -fsanitize=bool -fsanitize=address -fsanitize=leak

.PHONY: all clean

all: bitrot byteswap byteorder sha1 base64_encode base64_decode

bitrot: bitrot.c
	$(CC) $(CFLAGS) bitrot.c -o bitrot

byteswap: byteswap.c
	$(CC) $(CFLAGS) byteswap.c -o byteswap

byteorder: byteorder.c
	$(CC) $(CFLAGS) byteorder.c -o byteorder

sha1: sha1.c
	$(CC) $(CFLAGS) sha1.c ../sha1.c -o sha1

base64_encode: base64_encode.c
	$(CC) $(CFLAGS) base64_encode.c ../base64.c -o base64_encode

base64_decode: base64_decode.c
	$(CC) $(CFLAGS) base64_decode.c ../base64.c -o base64_decode

clean:
	rm -f bitrot
	rm -f byteswap
	rm -f byteorder
	rm -f sha1
	rm -f base64_encode
	rm -f base64_decode
