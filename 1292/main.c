#include <stdio.h>

int main() {
	int arr[1500] = {0, };
	int idx = 0;
	for(int i = 1; i < 50; i++) {
		for(int j = 0; j < i; j++) {
			arr[idx++] = i;
		}
	}
	
	int A, B;
	scanf("%d %d", &A, &B);
	
	int sum = 0;
	for(int i = A; i <= B; i++) {
		sum += arr[i - 1];
	}
	
	printf("%d\n", sum);
	
	return 0;
}