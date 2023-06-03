#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
	char longName[100];
	char * shortName = (char*)malloc(sizeof(char) * 100);
	scanf("%s", longName);
	int idx = 0;
	
	for(int i = 0; i < strlen(longName); i++) {
		if(isupper(longName[i])) {
			shortName[idx++] = longName[i];
		}
	}
	
	printf("%s\n", shortName);
	
	return 0;
}