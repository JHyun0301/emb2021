all : ledtest.c libMyPeri.a 
	arm-linux-gnueabi-gcc ledtest.c -l MyPeri -L. -o ledtest

libMyPeri.a :  led.o 
	arm-linux-gnueabi-ar rc libMyPeri.a led.o 

led.o : led.h led.c
	arm-linux-gnueabi-gcc -c led.c -o led.o

clean : 
	rm -rf *.o *.a *.elf

	
