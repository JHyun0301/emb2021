/*#ifndef _COLORLED_H_
#define _COLORLED_H_

void pwmActive(int bActivate, int pwmIndex);
void writePWMDuty(int  DutyCycle , int pwmIndex);
void writePWMPeriod(int frequency, int pwmIndex) ;
void pwmEnable(int bEnable, int pwmIndex);


#define MAX_SCALE_STEP		7

#define PWM_RED_BASE_SYS_PATH	"/sys/class/pwm/pwmchip0/pwm0/"
#define PWM_GREEN_BASE_SYS_PATH	"/sys/class/pwm/pwmchip1/pwm0/"
#define PWM_BLUE_BASE_SYS_PATH	"/sys/class/pwm/pwmchip2/pwm0/"

#define PWM_ENABLE_NAME		"enable"
#define PWM_FREQUENCY_NAME	"period"
#define PWM_DUTYCYCLE_NAME	"duty_cycle"
#define PWM_EXPORT "export"
#define PWM_UNEXPORT "unexport"

#define PWM_RED_BASE_SYS_PATH_PWM_ENABLE_NAME "/sys/class/pwm/pwmchip0/pwm0/enable"	
#define PWM_GREEN_BASE_SYS_PATH_PWM_ENABLE_NAME "/sys/class/pwm/pwmchip1/pwm0/enable"	
#define PWM_BLUE_BASE_SYS_PATH_PWM_ENABLE_NAME "/sys/class/pwm/pwmchip2/pwm0/enable"	

#define PWM_RED_BASE_SYS_PATH_PWM_EXPORT "/sys/class/pwm/pwmchip0/pwm0/export"	
#define PWM_GREEN_BASE_SYS_PATH_PWM_EXPORT "/sys/class/pwm/pwmchip1/pwm0/export"	
#define PWM_BLUE_BASE_SYS_PATH_PWM_EXPORT "/sys/class/pwm/pwmchip2/pwm0/export"	

#define PWM_RED_BASE_SYS_PATH_PWM_UNEXPORT "/sys/class/pwm/pwmchip0/pwm0/unexport"	
#define PWM_GREEN_BASE_SYS_PATH_PWM_UNEXPORT "/sys/class/pwm/pwmchip1/pwm0/unexport"	
#define PWM_BLUE_BASE_SYS_PATH_PWM_UNEXPORT "/sys/class/pwm/pwmchip2/pwm0/unexport"	

#define PWM_RED_BASE_SYS_PATH_PWM_FREQUENCY_NAME "/sys/class/pwm/pwmchip0/pwm0/period"	
#define PWM_GREEN_BASE_SYS_PATH_PWM_FREQUENCY_NAME "/sys/class/pwm/pwmchip1/pwm0/period"	
#define PWM_BLUE_BASE_SYS_PATH_PWM_FREQUENCY_NAME "/sys/class/pwm/pwmchip2/pwm0/period"


#define PWM_RED_BASE_SYS_PATH_PWM_DUTYCYCLE_NAME "/sys/class/pwm/pwmchip0/pwm0/duty_cycle"
#define PWM_GREEN_BASE_SYS_PATH_PWM_DUTYCYCLE_NAME "/sys/class/pwm/pwmchip1/pwm0/duty_cycle"	
#define PWM_BLUE_BASE_SYS_PATH_PWM_DUTYCYCLE_NAME "/sys/class/pwm/pwmchip2/pwm0/duty_cycle"

#define RED_INDEX	0
#define GREEN_INDEX	1
#define BLUE_INDEX	2

#define TRUE	1
#define FALSE	0

#define  PWM_FREQUENCY		1000

#define  MAX_INPUT_VALUE	1000

#endif*/

#ifndef _COLORLED_H_
#define _COLORLED_H_

void pwmActive(int bActivate);
void writePWMDuty(int  DutyCycle , int pwmIndex);
void writePWMPeriod(int frequency, int pwmIndex);
int pwmSetPeriod(int Period, int pwmIndex);
int pwmSetDuty(int dutyCycle, int pwmIndex);
int pwmActiveAll(void);
int pwmStartAll(void);
void pwmEnable(int bEnable);
int pwmLedInit(void);

#define MAX_SCALE_STEP      7

#define PWM_RED_BASE_SYS_PATH   "/sys/class/pwm/pwmchip0/pwm0/"
#define PWM_GREEN_BASE_SYS_PATH   "/sys/class/pwm/pwmchip1/pwm0/"
#define PWM_BLUE_BASE_SYS_PATH   "/sys/class/pwm/pwmchip2/pwm0/"

#define PWM_ENABLE_NAME      "enable"
#define PWM_FREQUENCY_NAME   "period"
#define PWM_DUTYCYCLE_NAME   "duty_cycle"
#define PWM_EXPORT "export"
#define PWM_UNEXPORT "unexport"

#define RED_INDEX   0
#define GREEN_INDEX   1
#define BLUE_INDEX   2

#define TRUE   1
#define FALSE   0

#define PWM_PERIOD_NS 1000

#define  PWM_FREQUENCY   1000

#define  MAX_INPUT_VALUE   100

#endif