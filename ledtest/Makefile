
all : libMyPeri.a 
	arm-linux-gnueabi-gcc test.c -l MyPeri -L. -lpthread -o test	

libMyPeri.a :  led.o button.o buzzer.o fnd.o colorled.o lcdtext.o touch.o
	arm-linux-gnueabi-ar rc libMyPeri.a led.o button.o buzzer.o fnd.o colorled.o lcdtext.o touch.o

led.o : led.h led.c
	arm-linux-gnueabi-gcc -c led.c -o led.o

button.o : button.h button.c
	arm-linux-gnueabi-gcc -c button.c -lpthread -o button.o

buzzer.o : buzzer.h buzzer.c
	arm-linux-gnueabi-gcc -c buzzer.c -o buzzer.o

fnd.o : fnd.h fnd.c
	arm-linux-gnueabi-gcc -c fnd.c -o fnd.o

colorled.o : colorled.h colorled.c
	arm-linux-gnueabi-gcc -c colorled.c -o colorled.o

lcdtext.o : lcdtext.h lcdtext.c
	arm-linux-gnueabi-gcc -c lcdtext.c -o lcdtext.o

touch.o : touch.h touch.c
	arm-linux-gnueabi-gcc -c touch.c -o touch.o

clean : 
	rm -rf *.o *.a *.elf

	
