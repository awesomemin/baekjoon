#include <stdio.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N);
	int Num = N;
	
	for(int i = 0; i < N; i++) {
		char word[100];
		scanf("%s", word);
		int len = strlen(word);
		int table[26] = {0, };
		int prev = -1;
		for(int j = 0; j < len; j++) {
			if(prev == word[j]) {
				continue;
			} else {
				if(table[word[j] - 97] == 0) {
					table[word[j] - 97] = 1;
				} else if (table[word[j] - 97] == 1) {
					Num -= 1;
					break;
				}
				prev = word[j];
			}
		}
	}
	
	printf("%d\n", Num);
}