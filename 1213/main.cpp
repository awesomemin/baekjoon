#include <iostream>
using namespace std;

int Alphabet[26] {0,};

bool isThereOddAlphabet = false;

bool isPossible() {
	int odd = 0;
	for(int i = 0; i < 26; i++) {
		if(Alphabet[i] % 2 != 0) {
			odd++;
		}
	}
	if(odd == 1) isThereOddAlphabet = true;
	if(odd >= 2) return false;
	else return true;
}


int main(void) {
	char ch;
	while(ch != '\n') {
		ch = cin.get();
		Alphabet[ch - 65]++;
	}
	
	if(!isPossible()) {
		cout<<"I'm Sorry Hansoo\n";
		return 0;
	}
	
	int oddIndex;	
	for(int i = 0; i < 26; i++) {
		if(Alphabet[i] % 2 != 0) {
			oddIndex = i;
			for(int j = 0; j < (Alphabet[i] - 1) / 2; j++) {
				printf("%c", i + 65);
			}
		} else {
			for(int j = 0; j < Alphabet[i] / 2; j++) {
				printf("%c", i + 65);
			}
		}
	}
	if(isThereOddAlphabet) {
		printf("%c", oddIndex + 65);
	}
	for(int i = 25; i >= 0; i--) {
		if(Alphabet[i] % 2 != 0) {
			for(int j = 0; j < (Alphabet[i] - 1) / 2; j++) {
				printf("%c", i + 65);
			}
		} else {
			for(int j = 0; j < Alphabet[i] / 2; j++) {
				printf("%c", i + 65);
			}
		}
	}
	
	return 0;
}