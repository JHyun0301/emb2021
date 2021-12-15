#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/input.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <sys/msg.h>

#include "led.h"
#include "buzzer.h"

#define LED_DRIVER_NAME "/dev/periled"

int main(int argc, char **argv)
{
	unsigned int data = 0;
	unsigned int onoff = 0;
    int scale;

	if (argc < 2)
	{
		perror(" Args number is less than 2\n");
		return 1;
	}

	data = strtol(argv[1], NULL, 16);
	printf("wrate data : 0x%X\n", data);
	onoff = strtol(argv[2], NULL, 16);
    scale = atoi(argv[1]);
    printf("scale : %d \n", scale);


   ledLibInit();
   buzzerInit();
	
   ledOnOff(data,onoff); 
   buzzerPlaySong(scale);

   
   ledStatus();


   sleep(1);
   buzzerStopSong();

   buzzerExit();
   ledLibExit();

	return 0;
}

