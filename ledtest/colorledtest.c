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

	red = MAX_INPUT_VALUE - red;
	green = MAX_INPUT_VALUE - green;
	blue = MAX_INPUT_VALUE - blue;
	
	// percentage
	int redduty = PWM_FREQUENCY * red / MAX_INPUT_VALUE;
	int greenduty = PWM_FREQUENCY * green / MAX_INPUT_VALUE;
	int blueduty = PWM_FREQUENCY * blue / MAX_INPUT_VALUE;
	
   pwmActiveAll();
   pwmSetDuty(redduty, 0); //R<-0
   pwmSetDuty(greenduty, 1); //G<-0
   pwmSetDuty(blueduty, 2); //B<-0
   pwmSetPeriod(PWM_PERIOD_NS, 0); pwmSetPeriod(PWM_PERIOD_NS, 1); pwmSetPeriod(PWM_PERIOD_NS, 2);
   pwmStartAll();
   return 0;
	

}

