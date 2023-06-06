#include <stdio.h>

int main() {
	int arr[5];
	for(int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}
	int temp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4 - i; j++) {
			if(arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < 5; i++) {
		sum += arr[i];
	}
	printf("%d\n%d\n",sum/5,arr[2]);
}