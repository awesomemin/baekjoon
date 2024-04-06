#include <iostream>
#include <algorithm>
using namespace std;

int board[100000][3];
int DP[2][3];

int max(int A, int B, int C) {
	int rtn = max(A, B);
	rtn = max(rtn, C);
	return rtn;
}

int min(int A, int B, int C) {
	int rtn = min(A, B);
	rtn = min(rtn, C);
	return rtn;
}

int main(void) {
	int N; cin>>N;
	for(int i = 0; i < N; i++) {
		cin>>board[i][0]>>board[i][1]>>board[i][2];
	}
	
	DP[0][0] = board[0][0];
	DP[0][1] = board[0][1];
	DP[0][2] = board[0][2];
	
	int maxAnswer = 0;
	int minAnswer = 987654321;
	
	for(int i = 1; i < N; i++) {
		DP[1][0] = max(DP[0][0], DP[0][1]) + board[i][0];
		DP[1][1] = max(DP[0][0], DP[0][1], DP[0][2]) + board[i][1];
		DP[1][2] = max(DP[0][1], DP[0][2]) + board[i][2];
		DP[0][0] = DP[1][0];
		DP[0][1] = DP[1][1];
		DP[0][2] = DP[1][2];
	}
	
	for(int i = 0; i < 3; i++) {
		maxAnswer = max(maxAnswer, DP[0][i]);
	}
	
	DP[0][0] = board[0][0];
	DP[0][1] = board[0][1];
	DP[0][2] = board[0][2];
	
	for(int i = 1; i < N; i++) {
		DP[1][0] = min(DP[0][0], DP[0][1]) + board[i][0];
		DP[1][1] = min(DP[0][0], DP[0][1], DP[0][2]) + board[i][1];
		DP[1][2] = min(DP[0][1], DP[0][2]) + board[i][2];
		DP[0][0] = DP[1][0];
		DP[0][1] = DP[1][1];
		DP[0][2] = DP[1][2];
	}
	
	for(int i = 0; i < 3; i++) {
		minAnswer = min(minAnswer, DP[0][i]);
	}
	
	cout<<maxAnswer<<" "<<minAnswer<<endl;
	
	return 0;
}