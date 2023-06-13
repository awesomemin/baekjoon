#include <iostream>

long fibonacci(long * arr, int n) {
	if(arr[n] != -1) {
		return arr[n];
	}
	arr[n] = fibonacci(arr, n - 1) + fibonacci(arr, n - 2);
	return arr[n];
}

int main() {
	int N;
	std::cin >> N;
	
	long table[100];
	for(int i = 0; i < 100; i++) {
		if(i == 0) {
			table[i] = 0;
		} else if(i == 1) {
			table[i] = 1;
		} else {
			table[i] = -1;
		}
	}
	
	std::cout << fibonacci(table, N) << std::endl;
	
	return 0;
}