#include <stdio.h>

int main() {
	int M;
	scanf("%d", &M);
	
	int currentBallPosition = 1;
	
	for(int i = 0; i < M; i++) {
		int X, Y;
		scanf("%d %d", &X, &Y);
		if(X == currentBallPosition) {
			currentBallPosition = Y;
		} else if (Y == currentBallPosition) {
			currentBallPosition = X;
		}
	}
	
	printf("%d\n", currentBallPosition);
	
	return 0;
}