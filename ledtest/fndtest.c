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
#include "fnd.h"


#define FND_DRIVER_NAME		"/dev/perifnd"

int main(int argc , char **argv)
{
    int number;
    int dot = 0;


	if (argc <  2)
	{
		printf("error!");
		return 1;
	}
		number = atoi(argv[1]);
        printf("number : %d\r\n", number);
        printf("dot : %d\r\n", dot);

        
        FNDWrite(300, 0);
        sleep(2);
        fndOff();
        count_discount(number);
        fndOff();
        FNDExit();


	
	return 0;
}
