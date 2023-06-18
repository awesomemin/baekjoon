#include <iostream>

int main() {
	long long int A, B;
	std::cin >> A >> B;
	if(B > A) {
		int temp = B;
		B = A;
		A = temp;
	}
	
	long long int i = 1;
	long long int lcm;
	while(1) {
		lcm = A * i;
		if(lcm % B == 0) {
			break;
		}
		i++;
	}
	std::cout << lcm << std::endl;
	
	return 0;
}