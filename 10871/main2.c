#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, X;
	scanf("%d %d", &N, &X);

	for(int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		if(num < X) {
			printf("%d ", num);
		}
	}
}