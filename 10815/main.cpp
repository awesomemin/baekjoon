#include <iostream>
#include <algorithm>

int search(int arr[], int left, int right, int target) {
	if(left > right) {
		return 0;
	}
	int mid = (left + right) / 2;
	if(arr[mid] == target) {
		return 1;
	} else if (arr[mid] < target) {
		return search(arr, mid + 1, right, target);
	} else {
		return search(arr, left, mid - 1, target);
	}
}

int main() {
	int N;
	std::cin >> N;
	int * cards = new int[N];
	for(int i = 0; i < N; i++) {
		std::cin >> cards[i];
	}
	std::sort(cards, cards + N);
	
	int M;
	std::cin >> M;
	int * targets = new int[M];
	for(int i = 0; i < M; i++) {
		std::cin >> targets[i];
	}
	
	for(int i = 0; i < M; i++) {
		std::cout << search(cards, 0, N - 1, targets[i]) << " ";
	}
	
	return 0;
}