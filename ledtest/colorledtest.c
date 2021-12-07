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
#include "colorled.h"
int fd;

int main(int argc, char *argv[])

 
{
	int red = atoi(argv[1]);
	int green = atoi(argv[2]);
	int blue = atoi(argv[3]);

	// inverse
	red = MAX_INPUT_VALUE - red;
	green = MAX_INPUT_VALUE - green;
	blue = MAX_INPUT_VALUE - blue;
	
	// percentage
	int redduty = PWM_FREQUENCY * red / MAX_INPUT_VALUE;
	int greenduty = PWM_FREQUENCY * green / MAX_INPUT_VALUE;
	int blueduty = PWM_FREQUENCY * blue / MAX_INPUT_VALUE;

	pwmActive(1,RED_INDEX);
    writePWMPeriod(PWM_FREQUENCY, RED_INDEX);
	writePWMDuty(redduty, RED_INDEX);
	pwmEnable(1,RED_INDEX);

    pwmActive(1,GREEN_INDEX);
	writePWMPeriod(PWM_FREQUENCY, GREEN_INDEX);
	writePWMDuty(greenduty, GREEN_INDEX);
	pwmEnable(1,GREEN_INDEX);
 
    pwmActive(1,BLUE_INDEX);
	writePWMPeriod(PWM_FREQUENCY, BLUE_INDEX);
	writePWMDuty(blueduty, BLUE_INDEX);
	pwmEnable(1,BLUE_INDEX);
	
    sleep(3);
	return 0;
}

