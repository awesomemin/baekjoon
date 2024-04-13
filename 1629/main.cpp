#include <iostream>
#include <cmath>
using namespace std;

unsigned long long A, B, C;

unsigned long long mul(int exponent) {
	if(exponent == 1) {
		return A % C;
	}
	if(exponent % 2 == 0) {
		return ((mul(exponent / 2) % C) * (mul(exponent / 2) % C)) % C;
	} else {
		return ((mul(exponent / 2 + 1) % C) * (mul(exponent / 2) % C)) % C;
	}
}

int main(void) {
	cin>>A>>B>>C;
	
	cout<<mul(B)<<endl;
	
	return 0;
}