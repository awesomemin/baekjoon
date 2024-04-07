#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int DP[100][100000] {0,};
int Weight[100] {0,};
int Value[100] {0,};

int main(void) {
	cin>>N>>K;
	for(int i = 0; i < N; i++) {
		cin>>Weight[i]>>Value[i];
	}
	
	for(int i = 0; i <= K; i++) {
		if(Weight[0] > i) {
			DP[0][i] = 0;
		} else {
			DP[0][i] = Value[0];
		}
	}
	
	for(int item = 1; item < N; item++) {
		for(int w = 0; w <= K; w++) {
			if(Weight[item] > w) {
				DP[item][w] = DP[item - 1][w];
			} else {
				DP[item][w] = max(DP[item - 1][w], Value[item] + DP[item - 1][w - Weight[item]]);
			}
		}
	}
	
	cout<<DP[N - 1][K]<<endl;
	
	return 0;
}