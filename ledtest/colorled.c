/*#include <stdio.h>
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
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "colorled.h"

int pwmActiveAll(void) //PWM 채널 활성화
{
   int fd = 0;
   fd = open ( "/sys/class/pwm/pwmchip0/export", O_WRONLY);
   write(fd,&"0",1);
   close(fd);
   fd = open ( "/sys/class/pwm/pwmchip1/export", O_WRONLY);
   write(fd,&"0",1);
   close(fd);
   fd = open ( "/sys/class/pwm/pwmchip2/export", O_WRONLY);
   write(fd,&"0",1);
   close(fd);
   return 1;
}

int pwmInactiveAll(void) //PWM 채널 비활성화
{
   int fd = 0;
   fd = open ( "/sys/class/pwm/pwmchip0/unexport", O_WRONLY);
   write(fd,&"0",1);
   close(fd);
   fd = open ( "/sys/class/pwm/pwmchip1/unexport", O_WRONLY);
   write(fd,&"0",1);
   close(fd);
   fd = open ( "/sys/class/pwm/pwmchip2/unexport", O_WRONLY);
   write(fd,&"0",1);
   close(fd);
   return 1;
}

int pwmSetDuty(int dutyCycle, int pwmIndex)
{
   int fd = 0;
   switch (pwmIndex)
   {
      case 0: 
         fd = open ( "/sys/class/pwm/pwmchip0/pwm0/duty_cycle", O_WRONLY); break;
      case 1: 
         fd = open ( "/sys/class/pwm/pwmchip1/pwm0/duty_cycle", O_WRONLY); break;
      case 2: 
      default: 
         fd = open ( "/sys/class/pwm/pwmchip2/pwm0/duty_cycle", O_WRONLY); break;
   }
   dprintf(fd, "%d", dutyCycle);
   close(fd);
   return 1;
}


int pwmSetPeriod(int Period, int pwmIndex)
{
   int fd = 0;
   switch (pwmIndex)
   {
      case 0: 
         fd = open ( "/sys/class/pwm/pwmchip0/pwm0/period", O_WRONLY); break;
      case 1: 
         fd = open ("/sys/class/pwm/pwmchip1/pwm0/period", O_WRONLY); break;
      case 2: 
      default: 
         fd = open ( "/sys/class/pwm/pwmchip2/pwm0/period", O_WRONLY); break;
   }
//printf ("Set pwm%d, Period:%d\r\n",pwmIndex, Period);
   dprintf(fd, "%d", Period);
   close(fd);
   return 1;
}

int pwmSetPercent(int percent, int ledColor)
{
   if ((percent <0) || (percent > 100))
   {
      printf ("Wrong percent: %d\r\n",percent);
      return 0;
   }
   int duty = (100- percent) * PWM_PERIOD_NS / 100;
//LED Sinking.
   pwmSetDuty(duty, ledColor);
   return 0;
}

int pwmStartAll(void)
{
   int fd = 0;
   fd = open ("/sys/class/pwm/pwmchip0/pwm0/enable", O_WRONLY);
   write(fd,&"1",1);
   close(fd);
   fd = open ( "/sys/class/pwm/pwmchip1/pwm0/enable", O_WRONLY);
   write(fd,&"1",1);
   close(fd);
   fd = open ( "/sys/class/pwm/pwmchip2/pwm0/enable", O_WRONLY);
   write(fd,&"1",1);
   close(fd);
   return 1;
}


int pwmLedInit(void)
{ 
   pwmActiveAll();
   pwmSetDuty(0, 0); //R<-0
   pwmSetDuty(0, 1); //G<-0
   pwmSetDuty(0, 2); //B<-0
   pwmSetPeriod(PWM_PERIOD_NS, 0); pwmSetPeriod(PWM_PERIOD_NS, 1); pwmSetPeriod(PWM_PERIOD_NS, 2);
   pwmStartAll();
   return 0;
}




