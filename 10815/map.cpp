#include <iostream>
#include <map>

int main() {
	std::map<int, int> my_map;
	
	int N;
	std::cin >> N;
	for(int i = 0; i < N; i++) {
		int card;
		std::cin >> card;
		my_map.insert({card, 1});
	}
	int M;
	std::cin >> M;
	for(int i = 0; i < M; i++) {
		int target_card;
		std::cin >> target_card;
		if(my_map[target_card] == 1) {
			std::cout << "1 ";
		} else {
			std::cout << "0 ";
		}
	}
}