#include <iostream>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;
	int * A = new int[N];
	int * B = new int[N];
	for(int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	
	for(int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	
	std::sort(A, A + N);
	std::sort(B, B + N, std::greater<int>());
	int min_sum = 0;
	
	for(int i = 0; i < N; i++) {
		min_sum += A[i] * B[i];
	}
	
	std::cout << min_sum << "\n";
	
	return 0;
}