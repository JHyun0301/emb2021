#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "led.h"

#define LED_DRIVER_NAME "/dev/periled"

/*int main(int argc, char **argv)
{
	unsigned int data = 0;
	unsigned int onoff = 0;
	int fd;
	if (argc < 2)
	{
		perror(" Args number is less than 2\n");
		return 1;
	}

	data = strtol(argv[1], NULL, 16);
	printf("wrate data : 0x%X\n", data);
	onoff = strtol(argv[2], NULL, 10);
	*/
int main(){


	ledLibInit();
	ledOnOff(8,1);
	ledStatus();
	ledLibExit();

	return 0;
}

