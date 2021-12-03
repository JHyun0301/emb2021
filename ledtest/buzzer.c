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
#include <dirent.h>

#define MAX_SCALE_STEP 8
#define BUZZER_BASE_SYS_PATH "/sys/bus/platform/devices/"
#define BUZZER_FILENAME "peribuzzer"
#define BUZZER_ENABLE_NAME "enable"
#define BUZZER_FREQUENCY_NAME "frequency"

char gBuzzerBaseSysDir[128];
int fd, fd1;

int buzzerInit(void){
	DIR * dir_info = opendir(BUZZER_BASE_SYS_PATH);
	int ifNotFound = 1;
	if (dir_info != NULL){
		while(1){
			struct dirent *dir_entry;
			dir_entry = readdir (dir_info);
			if(dir_entry == NULL) break;
			if(strncasecmp(BUZZER_FILENAME, dir_entry -> d_name, strlen(BUZZER_FILENAME)) == 0)
			{
				ifNotFound = 0;
				sprintf(gBuzzerBaseSysDir, "%s%s/", BUZZER_BASE_SYS_PATH, dir_entry -> d_name);
			}
		}
	}
	printf("find %s\n", gBuzzerBaseSysDir);
	return ifNotFound;

}

int setEnable(int benable){
	char path[200];
	sprintf(path, "%s%s", gBuzzerBaseSysDir, BUZZER_ENABLE_NAME);
     fd = open(path, O_WRONLY);
	 if(fd == -1){
	 printf("enable open error!\r\n");
	 }

	if(benable) write(fd, &"1", 1);
	else write(fd, &"0", 1);
	close(fd);
}

int setFrequency(int bfrequency){
  	char path[200];
	 sprintf(path, "%s%s", gBuzzerBaseSysDir, BUZZER_FREQUENCY_NAME);
	 fd1 = open(path, O_WRONLY);
	 dprintf(fd, "%d", bfrequency);	
	 close(fd);
}

int buzzerPlaySong(int scale){
	int frequency;

	if(scale == 1) frequency = 261; //도
	else if(scale == 2) frequency = 293; //레
	else if(scale == 3) frequency = 329; //미
	else if(scale == 4) frequency = 349; //파
	else if(scale == 5) frequency = 392; //솔
	else if(scale == 6) frequency = 440; //라
	else if(scale == 7) frequency = 496; //시
	else frequency = 523; //도
	
	
    setEnable(1);
	setFrequency(frequency);

}

int buzzerStopSong(void){
	 setEnable(0);
}

int buzzerExit(void){
	close(fd);
}

