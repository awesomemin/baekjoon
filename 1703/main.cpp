#include <stdio.h>

int main() {
	int a;
	int splittingFactor, cutLeaves;
	int totalLeaves;
	while (1) {
		totalLeaves = 1;
		scanf("%d", &a);
		if(a == 0)
			break;
		for(int i = 0; i < a; i++) {
			scanf("%d %d", &splittingFactor, &cutLeaves);
			totalLeaves *= splittingFactor;
			totalLeaves -= cutLeaves;
		}
		printf("%d\n", totalLeaves);
	}
}