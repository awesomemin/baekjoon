#include <stdio.h>

int main() {
	int X;
	scanf("%d", &X);
	
	int left, right;
	int line = 1;
	left = 1;
	right = 1;
	while(1) {
		if(left <= X && X <= right) {
			break;
		}
		line++;
		left = right + 1;
		right = right + line;
	}
	
	int numerator, denominator;
	
	//짝수 라인일 때
	if(line % 2 == 0) {
		numerator = X - left + 1;
		denominator = line + 1 - numerator;
	} else {
		denominator = X - left + 1;
		numerator = line + 1 - denominator;
	}
	
	printf("%d/%d\n", numerator, denominator);
	
	return 0;
}