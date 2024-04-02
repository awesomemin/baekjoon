#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int N; cin>>N;
	int count[26] {0,};
	for(int i = 0; i < N; i++) {
		string name;
		cin>>name;
		count[name[0] - 97]++;
	}
	
	bool isPREDAJA = true;
	for(int i = 0; i < 26; i++) {
		if(count[i] >= 5) {
			isPREDAJA = false;
			printf("%c", i+97);
		}
	}
	if(isPREDAJA) {
		cout<<"PREDAJA";
	}
	cout<<endl;
	
	
	return 0;
}