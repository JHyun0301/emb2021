#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/msg.h>
#include <pthread.h>
#include "button.h"

#define INPUT_DEVICE_LIST "dev/input/event"

#define PROBE_FILE "/proc/bus/input/devices"

#define HAVE_TO_FIND_1 "N: Name=\"ecube-button\"\n"
#define HAVE_TO_FIND_2 "H: Handlers=kbd event"

pthread_t buttonTh_id;

int probeButtonPath(char *newPath)
{
	int returnValue = 0; //button에 해당하는 event#를 찾았는지
	int number = 0; // 찾았으면 여기에 집어넣음
	FILE *fp = fopen(PROBE_FILE, "rt");

	while(!feof(fp))
	{
		char tmpStr[200];
		fgets(tmpStr, 200, fp);

		if (strcmp(tmpStr, HAVE_TO_FIND_1) == 0)
		{
			printf("YES! I found! : %s\r\n", tmpStr);
			returnValue = 1;
		}

		if ((returnValue == 1) && (strncasecmp(tmpStr, HAVE_TO_FIND_2, strlen(HAVE_TO_FIND_2)) == 0))
		{
		printf ("-->%s", tmpStr);
	        printf ("\t%c\r\n", tmpStr[strlen(tmpStr)-3]);
	        number = tmpStr[strlen(tmpStr)-3] - '0';
	        break;
		}
	}

                fclose(fp);
                if (returnValue == 1)
	        sprintf(newPath, "%s%d", INPUT_DEVICE_LIST, number);
                return returnValue;
}


int buttonThFunc(void){
	int readsize, inputIndex, fp;
	struct input_event stEvent;
	while(1)
	{
		readsize = read(fp, &stEvent, sizeof(stEvent));
		if (readsize != sizeof(stEvent))
		{
			continue;
		}
		if (stEvent.type == EV_KEY)
		{
			printf("EV_KEY(");
			switch(stEvent.code)
		{
			case KEY_VOLUMEUP : printf("Volume up key) : "); break;
			case KEY_HOME : printf("Home key): "); break;
			case KEY_SEARCH : printf("search key): "); break;
			case KEY_BACK : printf("Back key): "); break;
			case KEY_MENU : printf("Menu key): "); break;
			case KEY_VOLUMEDOWN : printf("Volume down key): "); break;
		}
		if(stEvent.value) 
			printf("pressed\n");
		else 
			printf("released\n");

	}
	else
		;
}
}

int buttonInit(void)
{
	char buttonPath[200] = {0, };
	if(probeButtonPath(buttonPath) == 0)
		return 0;
	int fd = open(buttonPath, O_RDONLY);
	int msgID = msgget(MESSAGE_ID, IPC_CREAT|0666);
	int err = pthread_create(&buttonTh_id, NULL, &buttonThFunc, NULL);
	return 1;
}

