#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	
	int min, max;
	for(int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		if(i == 0) {
			min = num;
			max = num;
		}
		if(min > num) {
			min = num;
		}
		if(max < num) {
			max = num;
		}
	}
	
	printf("%d\n", max * min);
	
	return 0;
}