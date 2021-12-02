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

	if (argc <  2)
	{
		printf("error!");
		return 1;
	}
		number = atoi(argv[2]);

        int FNDInit(void);
        int FNDWrite(number, 0);
        sleep(2);
        int fndOff(void);
        int count_discount(int number);
        sleep(number);
        int fndOff(void);
        int FNDExit(void);


	
	return 0;
}