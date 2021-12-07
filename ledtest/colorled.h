#ifndef _COLORLED_H_
#define _COLORLED_H_

void pwmActive(int bActivate);
void writePWMDuty(int  DutyCycle , int pwmIndex);
void writePWMPeriod(int frequency, int pwmIndex) ;
void pwmEnable(int bEnable);
int pwmLedInit(void);

#define MAX_SCALE_STEP		7

#define PWM_RED_BASE_SYS_PATH	"/sys/class/pwm/pwmchip0/pwm0/"
#define PWM_GREEN_BASE_SYS_PATH	"/sys/class/pwm/pwmchip1/pwm0/"
#define PWM_BLUE_BASE_SYS_PATH	"/sys/class/pwm/pwmchip2/pwm0/"

#define PWM_ENABLE_NAME		"enable"
#define PWM_FREQUENCY_NAME	"period"
#define PWM_DUTYCYCLE_NAME	"duty_cycle"
#define PWM_EXPORT "export"
#define PWM_UNEXPORT "unexport"

#define RED_INDEX	0
#define GREEN_INDEX	1
#define BLUE_INDEX	2

#define TRUE	1
#define FALSE	0

#define  PWM_FREQUENCY		100000

#define  MAX_INPUT_VALUE	100

#endif

