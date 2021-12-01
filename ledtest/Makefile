all : ledtest.c libMyPeri.a 
	arm-linux-gnueabi-gcc ledtest.c -l MyPeri -L. -o ledtest

libMyPeri.a :  led.o button.o
	arm-linux-gnueabi-ar rc libMyPeri.a led.o button.o 

led.o : led.h led.c
	arm-linux-gnueabi-gcc -c led.c -o led.o

button.o : button.h button.c
	arm-linux-gnueabi-gcc -c button.c -o button.o

clean : 
	rm -rf *.o *.a *.elf

	
