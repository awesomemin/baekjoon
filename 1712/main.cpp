#include <iostream>

int main() {
	long long int A, B, C;
	std::cin >> A >> B >> C;
	
	if(B >= C) {
		std::cout << "-1\n";
		return 0;
	}
	
	long long int R = (A / (C - B)) + 1;
	
	std::cout << R << "\n";
	
	return 0;
}