#include <stdio.h>

int d(int n) {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	a = (n / 1000) % 10;
	b = (n / 100) % 10;
	c = (n / 10) % 10;
	d = n % 10;
	return n + a + b + c + d;
	
}

int main() {
	int numbers[10000][2];
	for(int i = 0; i < 10000; i++) {
		numbers[i][0] = i;
		numbers[i][1] = 1;
	}
	
	for(int i = 1; i < 10000; i++) {
		int NotSelfNumber = d(i);
		for(int j = 0; j < 10000; j++) {
			if (numbers[j][0] == NotSelfNumber) {
				numbers[j][1] = 0;
			}
		}
	}
	
	for(int i = 1; i < 10000; i++) {
		if(numbers[i][1] == 1) {
			printf("%d\n", numbers[i][0]);
		}
	}
}