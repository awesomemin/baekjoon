#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int w, h;
bool visited[50][50];
int map[50][50];
int islandNum;
int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {-1, 1, 0, 0, 1, -1, 1, -1};

void findIsland(int x, int y) {
	visited[y][x] = true;
	if(map[y][x] == 0) return;
	queue<pair<int, int>> q;
	q.push({x, y});
	while(!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for(int i = 0; i < 8; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
			if(map[ny][nx] == 0) continue;
			if(visited[ny][nx]) continue;
			visited[ny][nx] = true;
			q.push({nx, ny});
		}
	}
	islandNum++;
}

int main(void) {
	while(1) {
		islandNum = 0;
		cin>>w>>h;
		if(w == 0 && h == 0) break;
		for(int y = 0; y < h; y++) {
			for(int x = 0; x < w; x++) {
				cin>>map[y][x];
				visited[y][x] = false;
			}
		}
		// for(int y = 0; y < h; y++) {
		// 	for(int x = 0; x < w; x++) {
		// 		cout<<map[y][x]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		for(int y = 0; y < h; y++) {
			for(int x = 0; x < w; x++) {
				if(!visited[y][x]) findIsland(x, y);
			}
		}
		cout<<islandNum<<endl;
	}
	
	return 0;
}