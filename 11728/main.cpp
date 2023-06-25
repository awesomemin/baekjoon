#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N, M;
	std::cin >> N >> M;
	int * A = new int[N];
	int * B = new int[M];
	
	for(int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	
	for(int i = 0; i < M; i++) {
		std::cin >> B[i];
	}
	
	int A_pointer = 0;
	int B_pointer = 0;
	
	int * new_arr = new int[N + M];
	
	while(A_pointer < N && B_pointer < M) {
		if(A[A_pointer] < B[B_pointer]) {
			new_arr[A_pointer + B_pointer] = A[A_pointer];
			A_pointer++;
		} else {
			new_arr[A_pointer + B_pointer] = B[B_pointer];
			B_pointer++;
		}
	}
	
	if(A_pointer == N) {
		while(B_pointer < M) {
			new_arr[A_pointer + B_pointer] = B[B_pointer];
			B_pointer++;
		}
	} else if(B_pointer == M) {
		while(A_pointer < N) {
			new_arr[A_pointer + B_pointer] = A[A_pointer];
			A_pointer++;
		}
	}
	
	for(int i = 0; i < N + M; i++) {
		std::cout << new_arr[i] << " ";
	}
	
	return 0;
}