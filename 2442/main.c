#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++) {
		for(int b = n - i; b > 0; b--) {
			printf(" ");
		}
		for(int s = 0; s < 2 * i - 1; s++) {
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}