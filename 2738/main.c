#include <stdio.h>

int main() {
	int matrix1[100][100];
	int matrix2[100][100];
	
	int N, M;
	
	scanf("%d %d", &N, &M);
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			int num;
			scanf("%d", &num);
			matrix1[i][j] = num;
		}
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			int num;
			scanf("%d", &num);
			matrix2[i][j] = num;
		}
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			printf("%d ", matrix1[i][j] + matrix2[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}