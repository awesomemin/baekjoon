#include <stdio.h>
#include <cstring>
#include <cstdlib>

int main() {
	int curTime[3];
	int startTime[3];
	
	char curTimeStr[9];
	scanf("%s", curTimeStr);
	char startTimeStr[9];
	scanf("%s", startTimeStr);
	
	char *temp;
	
	for(int i = 0; i < 3; i++) {
		if(i == 0) {
			curTime[i] = atoi(strtok(curTimeStr, ":"));
		} else {
			curTime[i] = atoi(strtok(NULL, ":"));
		}
	}
	
	for(int i = 0; i < 3; i++) {
		if(i == 0) {
			startTime[i] = atoi(strtok(startTimeStr, ":"));
		} else {
			startTime[i] = atoi(strtok(NULL, ":"));
		}
	}
	
	int result[3];
	
	if(curTime[2] <= startTime[2]) {
		result[2] = startTime[2] - curTime[2];
	} else {
		result[2] = (60 - curTime[2]) + startTime[2];
		curTime[1]++;
	}
	
	if(curTime[1] <= startTime[1]) {
		result[1] = startTime[1] - curTime[1];
	} else {
		result[1] = (60 - curTime[1]) + startTime[1];
		curTime[0]++;
	}
	
	if(curTime[0] <= startTime[0]) {
		result[0] = startTime[0] - curTime[0];
	} else {
		result[0] = (24 - curTime[0]) + startTime[0];
	}
	
	printf("%02d:%02d:%02d\n", result[0], result[1], result[2]);
	
	return 0;
}