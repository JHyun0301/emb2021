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

void pwmActive(int bActivate, int pwmIndex)
{
	char	strshellcmd[150];
	if ( bActivate==1 && pwmIndex==0 )
	{	
		fd = open(PWM_RED_BASE_SYS_PATH_PWM_EXPORT, O_WRONLY);
		write(fd, &"0", 1);
		close(fd);
	}
	else if ( bActivate==1 && pwmIndex==1 ) 
	{
		fd = open(PWM_GREEN_BASE_SYS_PATH_PWM_EXPORT, O_WRONLY);
		write(fd, &"0", 1);
		close(fd);
	}
	else if ( bActivate==1 && pwmIndex==2 ) 
	{
		fd = open(PWM_BLUE_BASE_SYS_PATH_PWM_EXPORT, O_WRONLY);
		write(fd, &"0", 1);
		close(fd);
	}
	else if ( bActivate==0 && pwmIndex==0 )
	{	
		fd = open(PWM_RED_BASE_SYS_PATH_PWM_UNEXPORT, O_WRONLY);
		write(fd, &"0", 1);
		close(fd);
	}
	else if ( bActivate==0 && pwmIndex==1 ) 
	{
		fd = open(PWM_GREEN_BASE_SYS_PATH_PWM_UNEXPORT, O_WRONLY);
		write(fd, &"0", 1);
		close(fd);
	}
	else if ( bActivate==0 && pwmIndex==2 ) 
	{
		
		fd = open(PWM_BLUE_BASE_SYS_PATH_PWM_UNEXPORT, O_WRONLY);
		write(fd, &"0", 1);
		close(fd);
	}

	else
	printf("error!\r\n");
}

void pwmEnable(int bEnable, int pwmIndex)
{
	char strshellcmd[150];
	if ( bEnable==1 && pwmIndex==0 )
	{	
		fd = open(PWM_RED_BASE_SYS_PATH_PWM_ENABLE_NAME, O_WRONLY);
		write(fd, &"1", 1);
		close(fd);
	}
	else if ( bEnable==1 && pwmIndex==1 ) 
	{
		fd = open(PWM_GREEN_BASE_SYS_PATH_PWM_ENABLE_NAME, O_WRONLY);
		write(fd, &"1", 1);
		close(fd);
	}
	else if ( bEnable==1 && pwmIndex==2 ) 
	{
		fd = open(PWM_BLUE_BASE_SYS_PATH_PWM_ENABLE_NAME , O_WRONLY);
		write(fd, &"1", 1);
		close(fd);
	}
	else if ( bEnable==0 && pwmIndex==0 )
	{	
		fd = open(PWM_RED_BASE_SYS_PATH_PWM_ENABLE_NAME, O_WRONLY);
		write(fd, &"0", 1);
		close(fd);
	}
	else if ( bEnable==0 && pwmIndex==1 ) 
	{
		fd = open(PWM_GREEN_BASE_SYS_PATH_PWM_ENABLE_NAME, O_WRONLY);
		write(fd, &"0", 1);
		close(fd);
	}
	else if ( bEnable==0 && pwmIndex==2 ) 
	{
		
		fd = open(PWM_BLUE_BASE_SYS_PATH_PWM_ENABLE_NAME, O_WRONLY);
		write(fd, &"0", 1);
		close(fd);
	}

	else
	printf("E error!\r\n");
}

void writePWMPeriod(int frequency, int pwmIndex) 
{
	if (pwmIndex == 0)
		fd = open(PWM_RED_BASE_SYS_PATH_PWM_FREQUENCY_NAME, O_WRONLY);
	else if(pwmIndex == 1)
		fd = open(PWM_GREEN_BASE_SYS_PATH_PWM_FREQUENCY_NAME, O_WRONLY);
	else
		fd = open(PWM_BLUE_BASE_SYS_PATH_PWM_FREQUENCY_NAME, O_WRONLY);

		dprintf(fd, "%d", frequency);
		close(fd);
	}


void writePWMDuty(int  DutyCycle , int pwmIndex)
{
	if (pwmIndex == 0)
		fd = open(PWM_RED_BASE_SYS_PATH_PWM_DUTYCYCLE_NAME, O_WRONLY);
	else if(pwmIndex == 1)
		fd = open(PWM_GREEN_BASE_SYS_PATH_PWM_DUTYCYCLE_NAME, O_WRONLY);
	else
		fd = open(PWM_BLUE_BASE_SYS_PATH_PWM_DUTYCYCLE_NAME, O_WRONLY);

		dprintf(fd, "%d", DutyCycle);
		close(fd);
	}




