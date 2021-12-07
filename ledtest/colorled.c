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

int fd = 0;

void pwmActive(int bActivate)
{
	if ( bActivate)
	{
		fd = open(PWM_RED_BASE_SYS_PATH PWM_EXPORT, O_WRONLY);
		write(fd, &"0", 1);
		close(fd);
		fd = open(PWM_GREEN_BASE_SYS_PATH PWM_EXPORT, O_WRONLY);
		write(fd, &"0", 1);
		close(fd);
		fd = open(PWM_BLUE_BASE_SYS_PATH PWM_EXPORT, O_WRONLY);
		write(fd, &"0", 1);
		close(fd);

	}
	else
	{
		fd = open(PWM_RED_BASE_SYS_PATH PWM_EXPORT, O_WRONLY);
		write(fd, &"1", 1);
		close(fd);
		fd = open(PWM_GREEN_BASE_SYS_PATH PWM_EXPORT, O_WRONLY);
		write(fd, &"1", 1);
		close(fd);
		fd = open(PWM_BLUE_BASE_SYS_PATH PWM_EXPORT, O_WRONLY);
		write(fd, &"1", 1);
		close(fd);
	}
}


void pwmEnable(int bEnable)
{
	if (bEnable == 1)
	{
		fd = open(PWM_RED_BASE_SYS_PATH PWM_ENABLE_NAME, O_WRONLY);
		write(fd, &"0", 1);
		close(fd);
		fd = open(PWM_GREEN_BASE_SYS_PATH PWM_ENABLE_NAME, O_WRONLY);
		write(fd, &"0", 1);
		close(fd);
		fd = open(PWM_BLUE_BASE_SYS_PATH PWM_ENABLE_NAME, O_WRONLY);
		write(fd, &"0", 1);
		close(fd);

	}
	else
	{
		fd = open(PWM_RED_BASE_SYS_PATH PWM_ENABLE_NAME, O_WRONLY);
		write(fd, &"1", 1);
		close(fd);
		fd = open(PWM_GREEN_BASE_SYS_PATH PWM_ENABLE_NAME, O_WRONLY);
		write(fd, &"1", 1);
		close(fd);
		fd = open(PWM_BLUE_BASE_SYS_PATH PWM_ENABLE_NAME, O_WRONLY);
		write(fd, &"1", 1);
		close(fd);
	}
}


void writePWMPeriod(int frequency, int pwmIndex) 
{
	if (pwmIndex == 0)
		fd = open(PWM_RED_BASE_SYS_PATH PWM_FREQUENCY_NAME, O_WRONLY);
	else if(pwmIndex == 1)
		fd = open(PWM_GREEN_BASE_SYS_PATH PWM_ENABLE_NAME, O_WRONLY);
	else
		fd = open(PWM_BLUE_BASE_SYS_PATH PWM_ENABLE_NAME, O_WRONLY);

		dprintf(fd, "%d", frequency);
		close(fd);
	}


void writePWMDuty(int  DutyCycle , int pwmIndex)
{
	if (pwmIndex == 0)
		fd = open(PWM_RED_BASE_SYS_PATH PWM_DUTYCYCLE_NAME, O_WRONLY);
	else if(pwmIndex == 1)
		fd = open(PWM_GREEN_BASE_SYS_PATH PWM_DUTYCYCLE_NAME, O_WRONLY);
	else
		fd = open(PWM_BLUE_BASE_SYS_PATH PWM_DUTYCYCLE_NAME, O_WRONLY);

		dprintf(fd, "%d", DutyCycle);
		close(fd);
	}


int pwmLedInit(void)
{ //Initialize
	pwmActive(1);

	writePWMDuty(0, 0); //R<-0
	writePWMDuty(0, 1); //G<-0
	writePWMDuty(0, 2); //B<-0

	pwmEnable(1);

	return 0; 
}
