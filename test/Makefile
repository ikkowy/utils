CC=gcc

all: bitrot byteswap byteorder sha1

bitrot: bitrot.c
	$(CC) -Wall bitrot.c -o bitrot

byteswap: byteswap.c
	$(CC) -Wall byteswap.c -o byteswap

byteorder: byteorder.c
	$(CC) -Wall byteorder.c -o byteorder

sha1: sha1.c
	$(CC) -Wall sha1.c ../sha1.c -o sha1

.PHONY: clean
clean:
	rm -f bitrot
	rm -f byteswap
	rm -f byteorder
	rm -f sha1
