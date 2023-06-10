#include <iostream>

int main() {
	int X;
	std::cin >> X;
	int result = 0;
	
	while(X != 0) {
		for(int i = 64; i >= 1; i = i / 2) {
			if(X - i >= 0) {
				X = X - i;
				result++;
			}
		}
	}
	
	std::cout << result << std::endl;
	
	return 0;
}