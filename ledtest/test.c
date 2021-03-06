#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/input.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <sys/msg.h>
#include <time.h>

#include "led.h"
#include "buzzer.h"
#include "fnd.h"
#include "lcdtext.h"
#include "colorled.h"
#include "touch.h"

#define LED_DRIVER_NAME "/dev/periled"

pthread_t buzzer_id;

void* buzzerFunc(void* arg){
while(1){
   buzzerPlaySong(2);
   sleep(3);
   buzzerPlaySong(0);
   sleep(3);
   buzzerPlaySong(1);
   sleep(3);
   buzzerPlaySong(0);
   sleep(3); 
   buzzerExit();}

}

int main(int argc, char **argv)
{
	unsigned int data = 0;
	unsigned int onoff = 0;
    int scale;
     int number;
    int dot = 0;
    stTextLCD  stlcd; 
	int lineFlag = 1;
    int red;
	int green;
	int blue;


    printf("lineFlag :%d\n", lineFlag);
	printf("string:%s\n"," ESCAPE GAME ");

    int lineFlag1 = 2;
    printf("lineFlag1 :%d\n", lineFlag1);
	printf("string:%s\n","    START    ");

		memcpy(stlcd.TextData[CMD_DATA_WRITE_LINE_1 - 1],"  ESCAPE  GAME  ",16);
        memcpy(stlcd.TextData[CMD_DATA_WRITE_LINE_2 - 1],"      START     ",16);


	data = strtol(argv[1], NULL, 16);
	printf("wrate data : 0x%X\n", data);

    scale = atoi(argv[1]);
    printf("scale : %d \n", scale);

    number = atoi(argv[1]);
     printf("number : %d\r\n", number);
    printf("dot : %d\r\n", dot);

    switch ( number){
        case 0 : red = 100; green = 0; blue = 0; break;
        case 1 : red = 100; green = 50;  blue = 0; break;
        case 2 : red = 100; green = 100;  blue = 0; break;
        case 3 : red = 0; green = 100;  blue = 0; break;
        case 4 : red = 0; green = 0;  blue = 50; break;
        case 5 : red = 0; green = 0;  blue = 100; break;
        case 6 : red = 100; green = 0;  blue = 100; break;
        case 7 : red = 100; green = 100;  blue = 100; break;

        default : red = 0; green = 0;  blue = 0; 
    }

    red = MAX_INPUT_VALUE - red;
	green = MAX_INPUT_VALUE - green;
	blue = MAX_INPUT_VALUE - blue;
	
	// percentage
	int redduty = PWM_FREQUENCY * red / MAX_INPUT_VALUE;
	int greenduty = PWM_FREQUENCY * green / MAX_INPUT_VALUE;
	int blueduty = PWM_FREQUENCY * blue / MAX_INPUT_VALUE;
	
    touchInit();

	int msgID = msgget( MESSAGE_ID, IPC_CREAT|0666);
	BUTTON_MSG_T recvMsg;
	while (1)
	{
		msgrcv(msgID, &recvMsg, sizeof (recvMsg)-sizeof (long int), 0, 0);
		//????????? ????????? ??????????????? ????????? ????????? ???????????? ????????? ?????????!
		switch (recvMsg.keyInput)
		{
			case 999:
				if (recvMsg.pressed == 1)
				{
					if (recvMsg.x <100 && recvMsg.y < 100)
					{
						printf ("You touched Lef-Top!\r\n");
					}
					else if (recvMsg.x > 500 && recvMsg.y < 100)
					{
						printf ("You touched Right-Top!\r\n");
					}
					else if (recvMsg.x <100 && recvMsg.y>300)
					{
						printf ("You touched Left-Bottom!\r\n");
					}
					else if (recvMsg.x > 500 && recvMsg.y > 300)
					{
						printf ("You touched Right-Bottom!\r\n");
					}
					else
					{
						printf ("You touched anywhere... maybe center? :%d %d\r\n",recvMsg.x, recvMsg.y);
					}
				}
			break;
		}
	
	}

   pwmActiveAll();
   ledLibInit();
   buzzerInit();
   lcdtextInit();


   pwmSetDuty(redduty, 0); //R<-0
   pwmSetDuty(greenduty, 1); //G<-0
   pwmSetDuty(blueduty, 2); //B<-0
   pwmSetPeriod(PWM_PERIOD_NS, 0); pwmSetPeriod(PWM_PERIOD_NS, 1); pwmSetPeriod(PWM_PERIOD_NS, 2);
   pwmStartAll();
   ledOnOff(data,1); 
    
   pthread_create(&buzzer_id, NULL, &buzzerFunc, NULL);

   FNDWrite(number, 0);
   lcdtextwrite(stlcd.TextData[CMD_DATA_WRITE_LINE_1-1], lineFlag);
   lcdtextwrite(stlcd.TextData[CMD_DATA_WRITE_LINE_2-1], lineFlag1);
    
 
   ledStatus();
   sleep(1);

   buzzerStopSong();
   fndOff();

    count_discount(number);
    fndOff();


    FNDExit();
   buzzerExit();
   ledLibExit();
   lcdExit();
	return 0;
}


