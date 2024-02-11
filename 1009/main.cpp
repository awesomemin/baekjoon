#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	
	for(int TestCase = 0; TestCase < T; TestCase++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int result = 1;
		for(int i = 0; i < b; i++) {
			result = (result * a) % 10;
		}
		if(result == 0)
			result = 10;
		printf("%d\n", result);
	}
	
	return 0;
}