#include <iostream>
#include <algorithm>
using namespace std;

int sticker[100000][2];
int dp[100000][2];

int max(int A, int B, int C) {
	int rtn = max(A, B);
	rtn = max(rtn, C);
	return rtn;
}

int main(void) {
	int T; cin>>T;
	for(int TESTCASE = 0; TESTCASE < T; TESTCASE++) {
		int n; cin>>n;
		for(int y = 0; y < 2; y++) {
			for(int x = 0; x < n; x++) {
				cin>>sticker[x][y];
			}
		}
		
		dp[0][0] = sticker[0][0];
		dp[0][1] = sticker[0][1];
		dp[1][0] = sticker[1][0] + sticker[0][1];
		dp[1][1] = sticker[1][1] + sticker[0][0];
		
		for(int i = 2; i < n; i++) {
			dp[i][0] = max(dp[i - 1][1], dp[i - 2][1], dp[i - 2][0]) + sticker[i][0];
			dp[i][1] = max(dp[i - 1][0], dp[i - 2][1], dp[i - 2][0]) + sticker[i][1];
		}
		
		cout<<max(dp[n - 1][0], dp[n - 1][1])<<endl;
	}
	
	return 0;
}