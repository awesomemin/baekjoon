#include <stdio.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		char string[30];
		char * chunk[30];
		int chunkNum = 0;
		if(i == 0) {
			getchar();
		}
		gets(string);
		char * ptr;
		ptr = strtok(string, " ");
		chunk[chunkNum++] = ptr;
		while(ptr != NULL) {
			ptr = strtok(NULL, " ");
			chunk[chunkNum++] = ptr;
		}
		printf("Case #%d: ", i + 1);
		for(int j = chunkNum - 2; j >= 0; j--) {
			printf("%s ", chunk[j]);
		}
		printf("\n");
	}
	
	return 0;
}