#include <iostream>
using namespace std;

int Fib[10000002];

int main(void) {
	int N; cin>>N;
	Fib[1] = 1;
	Fib[2] = 2;
	for(int i = 3; i <= N; i++) {
		Fib[i] = (Fib[i - 1] + Fib[i - 2]) % 10;
	}
	cout<<Fib[N]<<endl;
	
	return 0;
}