#include <iostream>

int isHansu(int num) {
	
	if(num < 100) {
		return 1;
	}
	
	if(num == 1000) {
		return 0;
	}
	
	int digit_1 = num / 100;
	int digit_2 = (num / 10) % 10;
	int digit_3 = num % 10;
	
	if(digit_1 - digit_2 == digit_2 - digit_3) {
		return 1;
	} else {
		return 0;
	}
	
}

int main() {
	
	int N;
	std::cin >> N;
	
	int result = 0;
	
	for(int i = 1; i <= N; i++) {
		if(isHansu(i) == 1) {
			result++;
		}
	}
	
	std::cout << result << std::endl;
}