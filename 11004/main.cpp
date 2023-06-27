#include <iostream>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin .tie(NULL);
	
	int N, K;
	std::cin >> N >> K;
	
	int * arr = new int[N];
	for(int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	
	std::sort(arr, arr + N);
	
	std::cout << arr[K - 1] << "\n";
	
	return 0;
}