#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include "temperature.h"

int main(int argc, char **argv)
{
	double temp = printtemp();
	printf("%0.2lf\r\n", temp);

	return 0;
}

