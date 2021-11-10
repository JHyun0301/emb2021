all: final.elf

final.elf:1.o main.c myProject.h
	gcc 1.o main.c -o final.elf

1.o:1.c myProject.h
	gcc 1.c -c 


clean:
	rm -rf *.o *.a *.elf



