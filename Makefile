all: final.elf

final.elf:
	gcc 1.o 2.o -o final.elf

1.o: 1.c common.h
	gcc -o 1.o 1.c

2.o: 2.c common.h
	gcc -o 2.o 2.c

clean:
	rm -rf *.o *.a *.elf



