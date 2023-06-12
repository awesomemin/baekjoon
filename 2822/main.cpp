#include <iostream>

void sort1(int arr[]) {
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 4; j++) {
			if(arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void sort2(int arr[][2]) {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 7; j++) {
			if(arr[j][0] < arr[j + 1][0]) {
				int tempV = arr[j][0];
				int tempI = arr[j][1];
				arr[j][0] = arr[j + 1][0];
				arr[j][1] = arr[j + 1][1];
				arr[j + 1][0] = tempV;
				arr[j + 1][1] = tempI;
			}
		}
	}
}

int sum(int arr[][2], int N) {
	int sum = 0;
	for(int i = 0; i < N; i++) {
		sum += arr[i][0];
	}
	return sum;
}

int main() {
	int scores[8][2];
	for(int i = 0; i < 8; i++) {
		std::cin >> scores[i][0];
		scores[i][1] = i + 1;
	}
	
	sort2(scores);
	
	std::cout << sum(scores, 5) << std::endl;
	
	int idxs[5];
	for(int i = 0; i < 5; i++) {
		idxs[i] = scores[i][1];
	}
	sort1(idxs);
	for(int i = 0; i < 5; i++) {
		std::cout << idxs[i] << " ";
	}
	
	return 0;
}