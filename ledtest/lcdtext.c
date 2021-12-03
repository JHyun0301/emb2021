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

#define TEXTLCD_DRIVER_NAME		"/dev/peritextlcd"

	stTextLCD  stlcd; 
	int fd;

int lcdtextInit(void){

    memset(&stlcd,0,sizeof(stTextLCD));   
}

int lcdtextwrite( const char *str1, int lineFlag)
{
    int len = strlen(str1);

    	stlcd.cmd = CMD_WRITE_STRING;
        stlcd.cmdData = lineFlag;
      //  strcpy(stlcd.TextData[lineFlag-1], str1);
        memcpy(stlcd.TextData[stlcd.cmdData - 1],str1,len);

    fd = open(TEXTLCD_DRIVER_NAME,O_RDWR);
	if ( fd < 0 )
	{
		printf("driver (//dev//peritextlcd) open error.\n");
		return 1;
	}
  
	write(fd,&stlcd,sizeof(stTextLCD));
}


int lcdExit(void){
    close(fd);
    return 1;
}