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

#define LED_DRIVER_NAME "/dev/periled"

int main(int argc, char **argv)
{
	unsigned int data = 0;
	unsigned int onoff = 0;
    int scale;
     int number;
    int dot = 0;
    stTextLCD  stlcd; 
	int lineFlag = 1;
    printf("lineFlag :%d\n", lineFlag);
	printf("string:%s\n"," ESCAPE GAME ");

    int lineFlag1 = 2;
    printf("lineFlag1 :%d\n", lineFlag1);
	printf("string:%s\n","    START    ");

		memcpy(stlcd.TextData[CMD_DATA_WRITE_LINE_1 - 1],"  ESCAPE  GAME  ",16);
        memcpy(stlcd.TextData[CMD_DATA_WRITE_LINE_2 - 1],"      START     ",16);


	data = strtol(argv[1], NULL, 16);
	printf("wrate data : 0x%X\n", data);

	onoff = strtol(argv[2], NULL, 16);

    scale = atoi(argv[1]);
    printf("scale : %d \n", scale);

    number = atoi(argv[1]);
     printf("number : %d\r\n", number);
    printf("dot : %d\r\n", dot);



   ledLibInit();
   buzzerInit();
   lcdtextInit();

   ledOnOff(data,onoff); 
   buzzerPlaySong(scale);
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

