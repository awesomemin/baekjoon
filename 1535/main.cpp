#include <iostream>
#include <algorithm>
using namespace std;

int N;
int HP[20];
int Joy[20];
int DP[101][20];

int main(void) {
	cin>>N;
	for(int i = 0; i < N; i++) {
		cin>>HP[i];
	}
	for(int i = 0; i < N; i++) {
		cin>>Joy[i];
	}
	for(int x = 0; x < N; x++) {
		for(int y = 1; y <= 100; y++) {
			if(x == 0) {
				if(y > HP[0]) {
					DP[y][x] = Joy[0];
				} else {
					DP[y][x] = 0;
				}
			} else {
				if(y - HP[x] >= 1) {
					DP[y][x] = max(DP[y][x - 1], DP[y - HP[x]][x - 1] + Joy[x]);
				} else {
					DP[y][x] = DP[y][x - 1];
				}
			}
		}
	}
	
	cout<<DP[100][N - 1]<<endl;
	
	return 0;
}