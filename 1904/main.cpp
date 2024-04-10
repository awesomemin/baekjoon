#include <iostream>
using namespace std;

int N;

unsigned long long DP[1000002];

int main(void) {
	cin>>N;
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;
	for(int i = 4; i <= N; i++) {
		DP[i] = (2 * DP[i - 2] + DP[i - 3]) % 15746;
	}
	cout<<DP[N]<<endl;
	
	return 0;
}