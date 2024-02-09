#include <stdio.h>
#include <stdlib.h>

int calculate_horizontal_d(int a, int b) {
	return abs(((a - 1) / 4) - ((b - 1) / 4));
}

int calculate_vertical_d(int a, int b) {
	return abs(((a - 1) % 4) - ((b - 1) % 4));
}

int main() {
	int num1, num2;
	
	scanf("%d %d", &num1, &num2);
	
	int horizontal_d, vertical_d;
	
	horizontal_d = calculate_horizontal_d(num1, num2);
	vertical_d = calculate_vertical_d(num1, num2);
	
	printf("%d\n", horizontal_d + vertical_d);
	
	return 0;
}