#include <iostream>
using namespace std;

long long dp[82] = {0, 1, 1,};

long long Fib(int num) {
	if(dp[num] != 0) {
		return dp[num];
	} else {
		dp[num] = Fib(num - 1) + Fib(num - 2);
		return dp[num];
	}
}

int main(void) {
	int N; cin>>N;
	Fib(N);
	
	if(N == 1) {
		cout<<4<<endl;
	} else {
		cout<<2 * (dp[N] * 2 + dp[N - 1])<<endl;
	}
	
	return 0;
}