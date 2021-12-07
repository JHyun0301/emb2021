#ifndef _BUTTON_H_
#define _BUTTON_H

#define MESSAGE_ID 1122
typedef struct
{
	long int messageNum;
	int keyInput;
	int pressed;
}BUTTON_MSG_T;

int probeButtonPath(char *newPath);
int buttonInit(void);
int buttonThread(void);
void* buttonThFunc(void *arg);

#endif

