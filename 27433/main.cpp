#include <iostream>
using namespace std;

long long factorial(long long n) {
	if(n == 1 || n == 0) return 1;
	return n * factorial(n-1);
}

int main(void) {
	long long N;
	cin>>N;
	cout<<factorial(N)<<endl;
	
	return 0;
}