#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void) {
	string strArr[101];
	int N; cin>>N;
	for(int i = 0; i < N; i++) {
		cin>>strArr[i];
	}
	for(int i = 0; i < N; i++) {
		for(auto ch : strArr[i]) {
			printf("%c", tolower(ch));
		}
		cout<<endl;
	}
	
	return 0;
}