#include <iostream>
using namespace std;

unsigned long long Fib[91];

int main(void) {
	int N; cin>>N;
	Fib[1] = 1;
	Fib[2] = 1;
	for(int i = 3; i <= N; i++) {
		Fib[i] = Fib[i - 1] + Fib[i - 2];
	}
	
	cout<<Fib[N]<<endl;
	
	return 0;
}