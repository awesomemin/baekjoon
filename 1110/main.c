#include <stdio.h>

int makeNewNumber(int result, int num, int cycle) {
	if(result == num && cycle != 0) {
		return cycle;
	}
	int a = num / 10;
	int b = num % 10;
	int newNum = (b * 10) + ((a + b) % 10);
	return makeNewNumber(result, newNum, cycle + 1);
}

int main() {
	
	int N;
	scanf("%d", &N);
	
	int cycle = makeNewNumber(N, N, 0);
	printf("%d\n", cycle);
	
	return 0;
}