#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	
	if(n == 0) {
		std::cout << 0 << std::endl;
		return 0;
	}
	
	double cut = std::round(n * 0.15);
	double * scores = new double[n];
	for(int i = 0; i < n; i++) {
		std::cin >> scores[i];
	}
	
	std::sort(scores, scores + n);
	
	double sum_of_scores = 0.0;
	for(int i = cut; i < n - cut; i++) {
		sum_of_scores += scores[i];
	}
	
	std::cout << std::round(sum_of_scores / (n - cut * 2)) << std::endl;
	
	return 0;
}