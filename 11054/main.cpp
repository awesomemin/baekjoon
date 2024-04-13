#include <iostream>
using namespace std;

int N;
int * numbers;
int * incDP;
int * decDP;

int main(void) {
	cin>>N;
	numbers = new int[N];
	incDP = new int[N] {1,};
	decDP = new int[N];
	
	for(int i = 0; i < N; i++) {
		decDP[i] = 0;
		if(i == N - 1) {
			decDP[i] = 1;
		}
	}
	
	for(int i = 0; i < N; i++) {
		cin>>numbers[i];
	}
	
	// if(N == 1) {
	// 	cout<<1<<endl;
	// 	return 0;
	// }
	
	for(int i = 1; i < N; i++) {
		int incMax = 0;
		for(int j = 0; j < i; j++) {
			if(numbers[i] > numbers[j]) {
				if(incMax < incDP[j]) {
					incMax = incDP[j];
				}
			}
		}
		incDP[i] = incMax + 1;
	}
	
	for(int i = N - 2; i >= 0; i--) {
		int decMax = 0;
		for(int j = N - 1; j > i; j--) {
			if(numbers[i] > numbers[j]) {
				if(decMax < decDP[j]) {
					decMax = decDP[j];
				}
			}
		}
		decDP[i] = decMax + 1;
	}
	
	// for(int i = 0; i < N; i++) {
	// 	cout<<incDP[i]<<" ";
	// }
	// cout<<endl;
	// for(int i = 0; i < N; i++) {
	// 	cout<<decDP[i]<<" ";
	// }
	// cout<<endl;

	
	int answer = 0;
	for(int i = 0; i < N; i++) {
		if(incDP[i] + decDP[i] - 1 > answer) {
			answer = incDP[i] + decDP[i] - 1;
		}
	}
	
	cout<<answer<<endl;
	
	delete[] numbers;
	delete[] incDP;
	delete[] decDP;
	
	return 0;
}