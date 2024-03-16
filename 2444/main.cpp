#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin>>N;
	
	for(int i = 1; i <= N; i++) {
		for(int space = 0; space < N - i; space++)
			cout<<' ';
		for(int star = 0; star < 2 * i - 1; star++)
			cout<<'*';
		cout<<endl;
	}
	
	for(int i = N - 1; i >= 1; i--) {
		for(int space = 0; space < N - i; space++)
			cout<<' ';
		for(int star = 0; star < 2 * i - 1; star++)
			cout<<'*';
		cout<<endl;
	}
	
	return 0;
}