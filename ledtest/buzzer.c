#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void setEnable(int benable){
	char path[200];
	sprintf(path, "%s%s", gBuzzerBaseSysDir, BUZZER_ENABLE_NAME);
     fd = open(path, O_WRONLY);
	if(benable) write(fd, &"1", 1);
	else write(fd, &"0", 1);
}

void setFrequency(int bfrequency){
  	char path[200];
	 sprintf(path, "%s%s", gBuzzerBaseSysDir, BUZZER_FREQUENCY_NAME);
	 fd1 = open(path, O_WRONLY);
	 dprintf(fd, "%d", bfrequency);	
}

int buzzerPlaySong(int scale){
	int frequency;

	switch(scale)
	{
		case 1 : frequency = 261; break;//도
		case 2 : frequency = 293; break; //레
		case 3 : frequency = 329; break; //미
		case 4 : frequency = 349; break; //파
		case 5 : frequency = 492; break; //솔
		case 6 : frequency = 440; break; //라
		case 7 : frequency = 493; break; //시
		case 8 : frequency = 523; break; //도
	}

	setEnable(1);
	setFrequency(frequency);
}



int buzzerStopSong(void){
	 setEnable(0);
}

int buzzerExit(void){
	close(fd);
}

