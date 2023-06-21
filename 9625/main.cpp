#include <iostream>

int main() {
	int K;
	std::cin >> K;
	
	int A = 1;
	int B = 0;
	for(int i = 0; i < K; i++) {		
		int new_B = B + A;
		int new_A = B;
		B = new_B;
		A = new_A;
	}
	
	std::cout << A << " " << B;
	
	return 0;
}