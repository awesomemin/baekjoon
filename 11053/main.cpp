#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int N; cin>>N;
	int * dp = new int[N] {1,};
	int * numbers = new int[N];
	for(int i = 0; i < N; i++) {
		cin>>numbers[i];
	}
	
	for(int i = 1; i < N; i++) {
		int Max = 1;
		for(int j = 0; j < i; j++) {
			if(numbers[i] > numbers[j]) {
				Max = max(Max, dp[j] + 1);
			}
		}
		dp[i] = Max;
	}
	
	int answer = 0;
	for(int i = 0; i < N; i++) {
		answer = max(answer, dp[i]);
	}
	
	cout<<answer<<endl;
	
	delete[] dp;
	delete[] numbers;
	return 0;
}