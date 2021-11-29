#include <stdlib.h>
#include <fcntl.h>
#include "led.h"
#include <unistd.h>
#include <stdio.h>


static unsigned int ledValue = 0;
static int fd = 0;


int ledOnOff(int ledNum, int onOff)
{
	int i=1;
	i = i<<ledNum;
	ledValue = ledValue& (~i);
	if (onOff != 0) ledValue |= i;
	write (fd, &ledValue, 4);
}

int ledStatus(void)
{
	printf("%d\r\n", ledValue);
	for(int j = 7; j>= 0; --j)
	{
		int result = ledValue >> j &1;
			printf("%d", result);
	}
}

int ledLibInit(void)
{
	fd = open("/dev/periled",O_WRONLY);
	ledValue = 0;
}

int ledLibExit(void)
{
	ledValue = 0;
	ledOnOff (0,0);
	close(fd);
}



