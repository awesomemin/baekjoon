#include <stdio.h>

int main() {
	int solution = 0;
		
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			char square;
			scanf("%c", &square);
			if(square == '\n') {
				j--;
				continue;
			}
			if(i % 2 == 0) {
				if(j % 2 == 0) {
					if(square == 'F') {
						solution++;
					}
				}
			} else {
				if(j % 2 == 1) {
					if(square == 'F') {
						solution++;
					}
				}
			}
		}
	}
	
	printf("%d\n", solution);
	
	return 0;
}