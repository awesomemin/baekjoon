#include <iostream>

int main() {
	int N, M;
	std::cin >> N >> M;
	int ** second_dimension_arr = new int * [N];
	for(int i = 0; i < N; i++) {
		second_dimension_arr[i] = new int[M];
	}
	
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			std::cin >> second_dimension_arr[y][x];
		}
	}
	
	int K;
	std::cin >> K;
	
	for(int test_case = 0; test_case < K; test_case++) {
		int sum = 0;
		int i, j, x, y;
		std::cin >> j >> i >> y >> x;
		for(int Y = j - 1; Y <= y - 1; Y++) {
			for(int X = i - 1; X <= x - 1; X++) {
				//std::cout << second_dimension_arr[Y][X] << std::endl;
				sum += second_dimension_arr[Y][X];
			}
		}
		std::cout << sum << std::endl;
	}
	
	return 0;
}