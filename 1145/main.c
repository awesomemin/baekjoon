#include <stdio.h>

int main() {
	
	int numbers[5];
	
	scanf("%d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4]);
	
	int solution = 1;
	
	while (1) {
		int numMultiple = 0;
		for(int i = 0; i < 5; i++) {
			if(solution % numbers[i] == 0)
				numMultiple++;
		}
		if(numMultiple >= 3) {
			break;
		}
		solution++;
	}
	
	printf("%d\n", solution);
	
	return 0;
}