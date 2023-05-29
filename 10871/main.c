#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N, X;
	scanf("%d %d", &N, &X);
	
	int * arr = (int*)malloc(sizeof(int) * N);
	for(int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		arr[i] = num;
	}
	
	for(int i = 0; i < N; i++) {
		if(arr[i] < X) {
			printf("%d ", arr[i]);
		}
	}
}