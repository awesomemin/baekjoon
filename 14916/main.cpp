#include <iostream>

int main() {
	int N;
	std::cin >> N;
	
	int number_of_coin = 0;
	
	while (N % 5 != 0) {
		N -= 2;
		number_of_coin++;
		if(N < 0) {
			std::cout << "-1" << std::endl;
			break;
		}
	}
	
	if(N % 5 == 0) {
		number_of_coin += (N / 5);
		std::cout << number_of_coin << std::endl;
	}
	
	return 0;
}