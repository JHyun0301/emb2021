#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/msg.h>
#include <pthread.h>
#include <dirent.h>
#include "buzzer.h"

int main(int argc, char **argv)
{
	int scale;
	if (argc < 2 )
	{
		printf("Error!\n");
		return 1;
	}
	scale = atoi(argv[1]);
    printf("scale : %d \n", scale);

 buzzerInit();
buzzerPlaySong(scale);
sleep(1);
buzzerStopSong();
buzzerExit();

}
