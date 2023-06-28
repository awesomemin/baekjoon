#include <iostream>

int main() {
	int N, M;
	std::cin >> N >> M;
	
	int box = 0;
	int weight = 0;
	
	for(int i = 0; i < N; i++) {
		int book;
		std::cin >> book;
		if(weight == 0) {
			box++;
		}
		
		if(weight + book < M) {
			weight = weight + book;
		} else if (weight + book == M) {
			weight = 0;
		} else {
			weight = book;
			box++;
		}
	}
	
	std::cout << box << "\n";
	
	return 0;
}