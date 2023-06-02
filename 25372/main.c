#include <stdio.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		char str[20];
		scanf("%s", str);
		if(strlen(str) >= 6 && strlen(str) <= 9) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	
	return 0;
}