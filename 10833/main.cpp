#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	
	int totalRemainApple = 0;
	
	for(int i = 0; i < N; i++) {
		int student, apple;
		scanf("%d %d", &student, &apple);
		totalRemainApple += (apple % student);
	}
	
	printf("%d\n", totalRemainApple);
	
	return 0;
}