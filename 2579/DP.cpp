#include <iostream>
using namespace std;

int dp[301];
int stairs[301];
int N;

int Max(int a, int b) {
	return (a > b) ? a : b;
}

int main(void) {
	cin>>N;
	
	for(int i = 0; i < N; i++) {
		cin>>stairs[i];
	}
	
	dp[0] = stairs[0];
	dp[1] = Max(stairs[0] + stairs[1], stairs[1]);
	dp[2] = Max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
	for(int i = 3; i < N; i++) {
		dp[i] = Max(dp[i - 3] + stairs[i - 1] + stairs[i], dp[i - 2] + stairs[i]);
	}
	
	cout<<dp[N - 1]<<endl;
	
	return 0;
}