#include <iostream>
using namespace std;

int main(void) {
	int N; cin>>N;
	for(int i = 0; i < N - 1; i++) {
		for(int blank = 0; blank < i; blank++) cout<<" ";
		for(int star = 0; star < 2 *(N - i) - 1; star++) cout<<"*";
		cout<<endl;
	}
	for(int i = 0; i < N; i++) {
		for(int blank = 0; blank < N - 1 - i; blank++) cout<<" ";
		for(int star = 0; star < 2 * i + 1; star++) cout<<"*";
		cout<<endl;
	}
	
	return 0;
}