all : libMyPeri.a 
	arm-linux-gnueabi-gcc buttontest.c -l MyPeri -L. -o test

libMyPeri.a :  led.o button.o buzzer.o fnd.o
	arm-linux-gnueabi-ar rc libMyPeri.a led.o button.o buzzer.o fnd.o

led.o : led.h led.c
	arm-linux-gnueabi-gcc -c led.c -o led.o

button.o : button.h button.c
	arm-linux-gnueabi-gcc -c button.c -lpthread -o button.o

buzzer.o : buzzer.h buzzer.c
	arm-linux-gnueabi-gcc -c buzzer.c -o buzzer.o

fnd.o : fnd.h fnd.c
	arm-linux-gnueabi-gcc -c fnd.c -o fnd.o

clean : 
	rm -rf *.o *.a *.elf

	
