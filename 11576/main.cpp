#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	unsigned long long A, B; cin>>A>>B;
	unsigned long long m; cin>>m;
	unsigned long long * numbers = new unsigned long long[m];
	for(int i = 0; i < m; i++) {
		cin>>numbers[i];
	}
	unsigned long long decimal = 0;
	for(int i = 0; i < m; i++) {
		decimal += numbers[i] * pow(A, m - i - 1);
	}
	//cout<<decimal<<endl;
	unsigned long long exponent = 20;
	while(decimal <= pow(B, exponent)) {
		exponent--;
	}
	//cout<<exponent<<endl;
	while(exponent > 0) {
		cout<<decimal / (unsigned long long)pow(B, exponent)<<" ";
		decimal %= (unsigned long long)pow(B, exponent);
		exponent--;
	}
	cout<<decimal<<endl;
	
	return 0;
}