#include <iostream>
using namespace std;

int Y, X;
int map[501][501] {0};
int DP[501][501];

int dx[4] {0, 1, 0, -1};
int dy[4] {-1, 0, 1, 0};

int dfs(int x, int y) {
	if(x == X - 1 && y == Y - 1) return 1;
	if(DP[y][x] != -1) return DP[y][x];
	
	DP[y][x] = 0;
	for(int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if(nextX < 0 || nextY < 0 || nextX >= X || nextY >= Y) {
			continue;
		}
		if(map[y][x] > map[nextY][nextX]) {
			DP[y][x] = DP[y][x] + dfs(nextX, nextY);
		}
	}
	return DP[y][x];
}

int main(void) {
	cin>>Y>>X;
	for(int y = 0; y < Y; y++) {
		for(int x = 0; x < X; x++) {
			cin>>map[y][x];
			DP[y][x] = -1;
		}
	}
	int answer;
	answer = dfs(0, 0);
	cout<<answer<<endl;
	
	return 0;
}