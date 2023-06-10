#include <stdio.h>
#include <string.h>

int max(int * arr, int len) {
	int max = 0;
	for(int i = 0; i < len; i++) {
		if(arr[i] >= max) {
			max = arr[i];
		}
	}
	return max;
}

int main() {
	char N[7];
	scanf("%s", N);
	int len = strlen(N);
	
	int table[10] = {0, };
	
	for(int i = 0; i < len; i++) {
		table[N[i] - 48]++;
	}
	
	if((table[6] + table[9]) % 2 == 0) {
		table[6] = (table[6] + table[9]) / 2;
	} else {
		table[6] = (table[6] + table[9]) / 2 + 1;
	}
	table[9] = 0;
	
	printf("%d\n", max(table, 9));
	
	return 0;
}