#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FND_NUM 6
#define FND_DATA_BUFF_LEN (MAX_FND_NUM + 2)

#define FND_DRIVER_NAME "/dev/perifnd"

int fd;

typedef struct FNDWriteDataForm_tag
{
    char DataNumeric[FND_DATA_BUFF_LEN]; //숫자 0-9
    char DataDot[FND_DATA_BUFF_LEN]; // 숫자 0 or 1
    char DataValid[FND_DATA_BUFF_LEN]; //숫자 0 or 1    
}stFndWriteForm, *pStFndWriteForm;


int FNDWrite(int num, int dotflag){

int temp, i;
stFndWriteForm stWriteData;

    for(i=0; i<MAX_FND_NUM; i++)
    {
        stWriteData.DataDot[i] = (dotflag & (0x1 << i))? 1:0;
        stWriteData.DataValid[i] = 1;
    }
    temp = num % 1000000;	stWriteData.DataNumeric[0]= temp /100000;
	temp = num % 100000;	stWriteData.DataNumeric[1]= temp /10000;
	temp = num % 10000;		stWriteData.DataNumeric[2] = temp /1000;
	temp = num %1000;		stWriteData.DataNumeric[3] = temp /100;
	temp = num %100;		stWriteData.DataNumeric[4] = temp /10;
							stWriteData.DataNumeric[5] = num %10;

    fd = open(FND_DRIVER_NAME, O_RDWR);
    if(fd<0)
    {
        printf("driver open error\r\n");
        return 0;
    }

    write(fd, &stWriteData, sizeof(stFndWriteForm));
 return 1;   
}
    

void fndOff()
{
int i;
stFndWriteForm stWriteData;
	for (i = 0; i < MAX_FND_NUM ; i++ )
	{
		stWriteData.DataDot[i] =  0;  
		stWriteData.DataNumeric[i] = 0;
		stWriteData.DataValid[i] = 0;
	}

	write(fd,&stWriteData,sizeof(stFndWriteForm));
}


int count_discount(int count){
	int counter = 300;

		while(1)
		{
			if (!FNDWrite(counter , 0))
				break;

			counter--;
			sleep(1);
			if (counter < 0 )
				break;
		}
	return 0;
}

int FNDExit(void){
    close(fd);
    return 1;
}  
