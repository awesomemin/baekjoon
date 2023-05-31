#include <stdio.h>
#include <stdlib.h>

int main() {
	char * S = (char*)malloc(sizeof(char) * 1000);
	int i;
	scanf("%s", S);
	scanf("%d", &i);
	printf("%c\n", S[i - 1]);
	
	return 0;
}