#include <stdio.h>
#include <cstdlib>

int main() {
	int testCase;
	scanf("%d", &testCase);
	
	for(int tc = 0; tc < testCase; tc++) {
		int p;
		scanf("%d", &p);
		int *price = (int*)malloc(sizeof(int) * p);
		char **name = (char**)malloc(sizeof(char *) * p);
		for(int i = 0; i < p; i++)
			name[i] = (char*)malloc(sizeof(char) * 20);
		for(int i = 0; i < p; i++) {
			scanf("%d %s", &price[i], name[i]);
		}
		int maxPrice = 0;
		int maxPriceIndex;
		for(int i = 0; i < p; i++) {
			if(price[i] > maxPrice)
				maxPrice = price[i];
		}
		for(int i = 0; i < p; i++) {
			if(price[i] == maxPrice) {
				maxPriceIndex = i;
				break;
			}
		}
		printf("%s\n", name[maxPriceIndex]);
	}
	
	return 0;
}