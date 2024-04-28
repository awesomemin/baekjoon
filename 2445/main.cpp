#include <iostream>
using namespace std;

int main(void) {
	int N; cin>>N;
	
	for(int row = 1; row < N; row++) {
		for(int star = 0; star < row; star++) cout<<"*";
		for(int blank = 0; blank < N - row; blank++) cout<<" ";
		for(int blank = 0; blank < N - row; blank++) cout<<" ";
		for(int star = 0; star < row; star++) cout<<"*";
		cout<<"\n";
	}
	for(int star = 0; star < N * 2; star++) cout<<"*";
	cout<<"\n";
	for(int row = N - 1; row >= 1; row--) {
		for(int star = 0; star < row; star++) cout<<"*";
		for(int blank = 0; blank < N - row; blank++) cout<<" ";
		for(int blank = 0; blank < N - row; blank++) cout<<" ";
		for(int star = 0; star < row; star++) cout<<"*";
		cout<<"\n";
	}
	
	return 0;
}