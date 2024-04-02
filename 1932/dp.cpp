#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ** dp;
int ** triangle;

int main(void) {
	cin>>N;
	dp = new int * [N];
	triangle = new int * [N];
	for(int i = 0; i < N; i++) {
		dp[i] = new int[i + 1];
		triangle[i] = new int[i + 1];
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j <= i; j++) {
			cin>>triangle[i][j];
		}
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j <= i; j++) {
			if(i == 0 && j == 0) {
				dp[i][j] = triangle[i][j];
				continue;
			}
			if(j == 0) {
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
				continue;
			}
			if(j == i) {
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
				continue;
			}
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
		}
	}
	
	int Max = 0;
	for(int i = 0; i < N; i++) {
		if(dp[N - 1][i] > Max) Max = dp[N - 1][i];
	}
	cout<<Max<<endl;
	
	for(int i = 0; i < N; i++) {
		delete[] dp[i];
		delete[] triangle[i];
	}
	delete[] dp;
	delete[] triangle;
	
	return 0;
}