#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M, N, H;
int Box[100][100][100];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int days = 0;

queue<vector<int>> q;

int main(void) {
	cin>>N>>M>>H;
	for(int z = 0; z < H; z++) {
		for(int y = 0; y < M; y++) {
			for(int x = 0; x < N; x++) {
				cin>>Box[z][y][x];
			}
		}
	}
	
	for(int z = 0; z < H; z++) {
		for(int y = 0; y < M; y++) {
			for(int x = 0; x < N; x++) {
				if(Box[z][y][x] == 1) {
					vector<int> tomato{x, y, z, 0};
					q.push(tomato);
				}
			}
		}
	}
	
	while(!q.empty()) {
		vector<int> tomato = q.front();
		q.pop();
		if(days < tomato[3]) {
			days = tomato[3];
		}
		
		for(int i = 0; i < 6; i++) {
			int nextX = tomato[0] + dx[i];
			int nextY = tomato[1] + dy[i];
			int nextZ = tomato[2] + dz[i];
			if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= M || nextZ < 0 || nextZ >= H) continue;
			if(Box[nextZ][nextY][nextX] == 1 || Box[nextZ][nextY][nextX] == -1) continue;
			Box[nextZ][nextY][nextX] = 1;
			vector<int> newTomato{nextX, nextY, nextZ, tomato[3] + 1};
			q.push(newTomato);
		}
	}
	
	for(int z = 0; z < H; z++) {
		for(int y = 0; y < M; y++) {
			for(int x = 0; x < N; x++) {
				if(Box[z][y][x] == 0) {
					days = -1;
				}
			}
		}
	}
	
	cout<<days<<endl;
	
	return 0;
}