#include <iostream>

int main() {
	int N;
	std::cin >> N;
	if(N % 2 == 0) {
		std::cout << "CY" << std::endl;
	} else {
		std::cout << "SK" << std::endl;
	}
}