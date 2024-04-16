#include <iostream>
using namespace std;

char words[5][15];

int main(void) {
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 15; j++) {
			words[i][j] = '\n';
		}
	}
	for(int i = 0; i < 5; i++) {
		cin>>words[i];
	}
	
	for(int i = 0; i < 15; i++) {
		for(int j = 0; j < 5; j++) {
			if(words[j][i] == '\n' || words[j][i] == NULL) continue;
			cout<<words[j][i];
		}
	}
	
	return 0;
}