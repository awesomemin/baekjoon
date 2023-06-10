#include <stdio.h>
#include <string.h>

int main() {
	char N[10];
	scanf("%s", N);
	int len = strlen(N);
	int table[10] = {0,};
	for(int i = 0; i < len; i++) {
		table[N[i] - 48]++;
	}
	
	for(int i = 9; i >= 0; i--) {
		for(int j = 0; j < table[i]; j++) {
			printf("%d", i);
		}
	}
	printf("\n");
	
	return 0;
}