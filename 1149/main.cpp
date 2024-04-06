#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1000][3];
int prices[1000][3];

int main(void) {
	cin>>N;
	for(int i = 0; i < N; i++) {
		int R, G, B; cin>>R>>G>>B;
		prices[i][0] = R;
		prices[i][1] = G;
		prices[i][2] = B;
	}
	
	dp[0][0] = prices[0][0];
	dp[0][1] = prices[0][1];
	dp[0][2] = prices[0][2];
	
	for(int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + prices[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + prices[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + prices[i][2];
	}
	
	int answer = 987654321;
	for(int i = 0; i < 3; i++) {
		answer = min(answer, dp[N-1][i]);
	}
	cout<<answer<<endl;
	
	return 0;
}