#include <iostream>

int main() {
	int N, M;
	std::cin >> N >> M;
	
	int set = N / 6;
	int each = N - (set * 6);
	
	int min_set_price;
	int min_each_price;
	
	for(int i = 0; i < M; i++) {
		int set_price, each_price;
		std::cin >> set_price >> each_price;
		if(i == 0) {
			min_set_price = set_price;
			min_each_price = each_price;
		} else {
			if(min_set_price > set_price) {
				min_set_price = set_price;
			}
			if(min_each_price > each_price) {
				min_each_price = each_price;
			}
		}
	}
	
	if(min_set_price > min_each_price * 6) {
		std::cout << min_each_price * N << "\n";
	} else if (each != 0 && min_set_price * (set + 1) < min_set_price * set + min_each_price * each) {
		std::cout << min_set_price * (set + 1) << "\n";
	} else {
		std::cout << min_set_price * set + min_each_price * each << "\n";
	}
	
	return 0;
}