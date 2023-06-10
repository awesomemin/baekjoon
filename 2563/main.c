#include <stdio.h>

int main() {
	int paper[100][100] = {0, };
	int N;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		for(int xx = x; xx < x + 10; xx++) {
			for(int yy = y; yy < y + 10; yy++) {
				paper[yy][xx] = 1;
			}
		}
	}
	int result = 0;
	for(int i = 0; i < 100; i++) {
		for(int j = 0; j < 100; j++) {
			if(paper[i][j] == 1) {
				result++;
			}
		}
	}
	printf("%d\n", result);
}