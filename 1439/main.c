#include <stdio.h>
#include <string.h>

int main() {
	char S[1000000];
	scanf("%s", S);
	int table[2];
	int prev = -1;
	int len = strlen(S);
	
	for(int i = 0; i < len; i++) {
		if(prev != (S[i]-48)) {
			prev = (S[i]-48);
			table[(S[i]-48)]++;
		}
	}
	
	printf("%d\n", table[0] > table[1] ? table[1] : table[0]);
	
	
	return 0;
}