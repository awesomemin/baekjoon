#include <iostream>

int isPSN(int num) {
	for(int i = 1; i <= 100; i++) {
		if(num == i * i) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int M, N;
	std::cin >> M;
	std::cin >> N;
	int sum = 0;
	int first = 0;
	for(int i = M; i <= N; i++) {
		if(isPSN(i) == 1) {
			if(first == 0) {
				first = i;
			}
			sum += i;
		}
	}
	if(first == 0) {
		std::cout << -1 << std::endl;
	} else {
		std::cout << sum << std::endl << first << std::endl;
	}
	
	return 0;
}