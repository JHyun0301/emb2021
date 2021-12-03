#ifndef _BUTTON_H_
#define _BUTTON_H

#define MESSAGE_ID 1122
typedef struct
{
	long int messageNum;
	int keyInput;
	int pressed;
}BUTTON_MSG_T;

int buttonInit(void);
void* buttonThFunc(void *arg);
int probeButtonPath(char *newPath);

#endif

