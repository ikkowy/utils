CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -fsanitize=unreachable -fsanitize=bool -fsanitize=address -fsanitize=leak

all: bitrot byteswap byteorder sha1

bitrot: bitrot.c
	$(CC) $(CFLAGS) bitrot.c -o bitrot

byteswap: byteswap.c
	$(CC) $(CFLAGS) byteswap.c -o byteswap

byteorder: byteorder.c
	$(CC) $(CFLAGS) byteorder.c -o byteorder

sha1: sha1.c
	$(CC) $(CFLAGS) sha1.c ../sha1.c -o sha1

.PHONY: clean
clean:
	rm -f bitrot
	rm -f byteswap
	rm -f byteorder
	rm -f sha1
