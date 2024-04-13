#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string A, B;
int ALen, BLen;

int DP[1001][1001];

int LCS(string &A, string &B, int a, int b) {
	if(a == -1 || b == -1) {
		return 0;
	}
	if(DP[a][b] != -1) {
		return DP[a][b];
	}
	if(A[a] == B[b]) {
		DP[a][b] = 1 + LCS(A, B, a - 1, b - 1);
		return DP[a][b];
	} else {
		DP[a][b] = max(LCS(A, B, a - 1, b),
					   LCS(A, B, a, b - 1));
		return DP[a][b];
	}
}

int main(void) {
	cin>>A>>B;
	ALen = A.size() - 1;
	BLen = B.size() - 1;
	fill(&DP[0][0], &DP[1000][1001], -1);
	
	cout<<LCS(A, B, ALen, BLen)<<endl;
	
	return 0;
}