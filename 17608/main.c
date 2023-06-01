#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	int * Bars = (int*)malloc(sizeof(int) * N);
	for(int i = N - 1; i >= 0; i--) {
		int h;
		scanf("%d", &h);
		Bars[i] = h;
	}
	
	int currentlyHighestBar = 0;
	int numOfBarsCanBeSeen = 0;
	for(int i = 0; i < N; i++) {
		if(Bars[i] > currentlyHighestBar) {
			currentlyHighestBar = Bars[i];
			numOfBarsCanBeSeen++;
		}
	}
	
	printf("%d\n", numOfBarsCanBeSeen);
	
	return 0;
}