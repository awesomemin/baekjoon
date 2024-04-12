#include <iostream>
using namespace std;

int DP[1025][1025] {0,};

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M; cin>>N>>M;
	for(int x = 1; x <= N; x++) {
		for(int y = 1; y <= N; y++) {
			int input; cin>>input;
			DP[y][x] = DP[y][x - 1] + DP[y - 1][x] + input - DP[y - 1][x - 1];
		}
	}
	
	for(int i = 0; i < M; i++) {
		int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
		cout<<DP[y2][x2] - DP[y1 - 1][x2] - DP[y2][x1 - 1] + DP[y1 - 1][x1 - 1]<<"\n";
	}
	
	return 0;
}