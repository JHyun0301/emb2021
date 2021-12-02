#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/msg.h>
#include <pthread.h>
#include "button.h"

int main(int argc, char **argv)
{
	int scale;
	if (argc < 2 || findBuzzerSysPath() )
	{
		printf("Error!\n");
		return 1;
	}
	scale = atoi(argv[1]);
    printf("scale : %d \n", scale);

int buzzerInit(void);
int buzzerPlaySong(int scale);
sleep(5);
int buzzerStopSong(void);
int buzzerExit(void);

}