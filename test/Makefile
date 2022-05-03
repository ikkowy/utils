CC=gcc

all: bitrot byteswap byteorder

bitrot: bitrot.c
	$(CC) bitrot.c -o bitrot

byteswap: byteswap.c
	$(CC) byteswap.c -o byteswap

byteorder: byteorder.c
	$(CC) byteorder.c -o byteorder

.PHONY: clean
clean:
	rm -f bitrot
	rm -f byteswap
	rm -r byteorder
