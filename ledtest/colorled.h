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

#define RED_INDEX   0
#define GREEN_INDEX   1
#define BLUE_INDEX   2

#define TRUE   1
#define FALSE   0

#define PWM_PERIOD_NS 1000

#define  PWM_FREQUENCY   1000

#define  MAX_INPUT_VALUE   100

#endif