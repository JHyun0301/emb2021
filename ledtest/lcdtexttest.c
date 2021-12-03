#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "lcdtext.h"

int main(int argc , char **argv)
{
    stTextLCD  stlcd; 
	int lineFlag = strtol(argv[1],NULL,10);
	printf("lineFlag :%d\n", lineFlag);
	printf("string:%s\n",argv[2]);

     if ( lineFlag == 1) 
		stlcd.cmdData = CMD_DATA_WRITE_LINE_1;
	else if ( lineFlag == 2) 
		stlcd.cmdData = CMD_DATA_WRITE_LINE_2;

   int len = strlen(argv[2]);
	if ( len > COLUMN_NUM)//16
		memcpy(stlcd.TextData[stlcd.cmdData - 1],argv[2],COLUMN_NUM);
	else
		memcpy(stlcd.TextData[stlcd.cmdData - 1],argv[2],len);

 lcdtextInit();
 lcdtextwrite(stlcd.TextData[stlcd.cmdData-1], lineFlag);
 lcdExit();
}

