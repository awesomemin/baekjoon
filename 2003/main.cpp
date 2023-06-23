#include <iostream>

int main() {
	int N, M;
	
	std::cin >> N >> M;
	
	int * arr = new int[N];
	
	for(int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	
	int result = 0;
	
	for(int i = 0; i < N; i++) {
		int sum = 0;
		for(int j = i; j < N; j++) {
			sum += arr[j];
			if(sum == M) {
				result++;
				break;
			}
			if(sum > M) {
				break;
			}
		}
	}
	
	std::cout << result << std::endl;
	
	return 0;
}