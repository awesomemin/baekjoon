#include <stdio.h>

int main() {
	int totalPrice;
	scanf("%d", &totalPrice);
	
	int tempPrice;
	for(int i = 0; i < 9; i++) {
		scanf("%d", &tempPrice);
		totalPrice -= tempPrice;
	}
	
	printf("%d\n", totalPrice);
	
	return 0;
}