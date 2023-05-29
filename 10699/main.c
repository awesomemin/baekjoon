#include <stdio.h>
#include <time.h>

int main() {
	struct tm* timeStruct;
	time_t t = time(NULL);
	timeStruct = localtime(&t);
	
	int year = timeStruct -> tm_year + 1900;
	int month = timeStruct -> tm_mon + 1;
	int day = timeStruct -> tm_mday;
	
	printf("%d-%02d-%d\n", year, month, day);
	
	return 0;
}