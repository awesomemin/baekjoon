#include <iostream>

int main() {
	int X;
	std::cin >> X;
	int N;
	std::cin >> N;
	
	int sum = 0;
	
	for(int i = 0; i < N; i++) {
		int a, b;
		std::cin >> a >> b;
		sum += a * b;
	}
	
	if(sum == X) {
		std::cout << "Yes" << std::endl;
	} else {
		std::cout << "No" << std::endl;
	}
	
}