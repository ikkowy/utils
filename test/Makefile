CC=gcc

all: bitrot bitswap

bitrot: bitrot.c
	$(CC) bitrot.c -o bitrot

bitswap: bitswap.c
	$(CC) bitswap.c -o bitswap

.PHONY: clean
clean:
	rm -f bitrot
	rm -f bitswap
