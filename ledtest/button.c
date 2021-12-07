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

#define INPUT_DEVICE_LIST "/dev/input/event"

#define PROBE_FILE "/proc/bus/input/devices"

#define HAVE_TO_FIND_1 "N: Name=\"ecube-button\"\n"
#define HAVE_TO_FIND_2 "H: Handlers=kbd event"

pthread_t buttonTh_id;
int msgID;

int probeButtonPath(char *newPath)  //event번호찾는 함수 
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


 void* buttonThFunc(void *arg){
        int readsize, inputIndex, fp;
	struct input_event stEvent;
	
	BUTTON_MSG_T messageTxData; 
	msgID = msgget(MESSAGE_ID, IPC_CREAT|0666);

	while(1)
	{
		readsize = read(fp, &stEvent, sizeof(stEvent));
		if (readsize != sizeof(stEvent))
		{
			continue;
		}
		if ((stEvent.type == EV_KEY) && (stEvent.value ==0))
		{
			messageTxData.keyInput = stEvent.code;
			msgsnd(msgID, &messageTxData, sizeof(messageTxData.keyInput),0);
		}	
	}
}

int buttonInit(void)
{
	printf("start\n");
	struct input_event stEvent;
	BUTTON_MSG_T messageRxData;
	char buttonPath[200] = {0, };  //어느파일을 받아야하는지 받아옴
	if(probeButtonPath(buttonPath) == 0)
	{
		printf ("ERROR! File Not Found!\r\n");
		printf ("Did you insmod?\r\n");
		return 0;
	}  //오류시

	msgID = msgget(MESSAGE_ID, IPC_CREAT|0666);
	printf ("buttonPath: %s\r\n", buttonPath);
	int fd = open(buttonPath, O_RDONLY);
	if(fd == -1) printf("open error\r\n");


	
	int err = pthread_create(&buttonTh_id, NULL, &buttonThFunc, NULL);
	if(err !=0 ) printf("Thread create error!\r\n");
	else printf("thread create success!");

	while(1) 
	{
		int msgValue, msgValue1= 0;
		msgValue = msgrcv(msgID,&messageRxData, sizeof(messageRxData.keyInput),0,0);
		msgValue1 = msgrcv(msgID, &messageRxData, sizeof(messageRxData.pressed),0,0);

		if (messageRxData.keyInput != 0)
		{
			printf("EV_KEY(");
			switch(messageRxData.keyInput)
			{
				case KEY_VOLUMEUP : printf("KEY_VOLUMUP): "); break;
				case KEY_HOME : printf("KEY_HOME): "); break;
				case KEY_SEARCH : printf("KEY_SEARCH): "); break;
				case KEY_BACK : printf("KEY_BACK): "); break;
			 	case KEY_MENU : printf("KEY_MENU): "); break;
				case KEY_VOLUMEDOWN : printf("KEY_VOLUMDOWN): "); break;
			}
			if(messageRxData.pressed !=0) printf("pressed\n"); 
			else printf("released\n");		
		}
		else
			;
	}

}


