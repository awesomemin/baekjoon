#include <iostream>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;
	
	int * ropes = new int[N];
	for(int i = 0; i < N; i++) {
		std::cin >> ropes[i];
	}
	std::sort(ropes, ropes + N);
	
	int * weight = new int[N];
	for(int i = 0; i < N; i++) {
		weight[i] = ropes[i] * (N - i);
	}
	
	int max = 0;
	for(int i = 0; i < N; i++) {
		if(weight[i] > max) {
			max = weight[i];
		}
	}
	
	std::cout << max << std::endl;
	
	return 0;
}