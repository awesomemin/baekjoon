#include <iostream>
using namespace std;

int recursiveFibCallCount = 0;
int dpFibCallCount = 0;

int recursiveFib(int num) {
	if(num == 1 || num == 2) {
		recursiveFibCallCount++;
		return 1;
	}
	else return recursiveFib(num - 1) + recursiveFib(num - 2);
}

int dp[50] = {-1, 1, 1, };
int dpFib(int num) {
	if(dp[num] != 0) return dp[num];
	else {
		dp[num] = dpFib(num - 1) + dpFib(num - 2);
		dpFibCallCount++;
		return dp[num];
	}
}

int main(void) {
	int n; cin>>n;
	recursiveFib(n);
	dpFib(n);
	cout<<recursiveFibCallCount<<" "<<dpFibCallCount<<"\n";
	
	return 0;
}