#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int h, w;

vector<vector<int>> Map;
vector<vector<bool>> visitedMap;
queue<vector<int>> q;

void bfs(int startX, int startY) {
	vector<int> startPoint = {startX, startY, 0};
	q.push(startPoint);
	visitedMap[startY][startX] = true;
	
	while(!q.empty()) {
		vector<int> point = q.front();
		q.pop();
		Map[point[1]][point[0]] = point[2];
		for(int i = 0; i < 4; i++) {
			int nextX = point[0] + dx[i];
			int nextY = point[1] + dy[i];
			if(nextX < 0 || nextX >= w || nextY < 0 || nextY >= h) continue;
			if(visitedMap[nextY][nextX] == true) continue;
			if(Map[nextY][nextX] == 0) continue;
			vector<int> temp = {nextX, nextY, point[2] + 1};
			visitedMap[nextY][nextX] = true;
			q.push(temp);
		}
	}
}

int main(void) {
	cin>>h>>w;
	for(int i = 0; i < h; i++) {
		vector<int> row;
		for(int j = 0; j < w; j++) {
			int temp; cin>>temp;
			row.push_back(temp);
		}
		Map.push_back(row);
	}
	
	for(int y = 0; y < h; y++) {
		vector<bool> row;
		for(int x = 0; x < w; x++) {
			row.push_back(false);
		}
		visitedMap.push_back(row);
	}
	
	int startPointX, startPointY;
	for(int y = 0; y < h; y++) {
		for(int x = 0; x < w; x++) {
			if(Map[y][x] == 2) {
				startPointX = x;
				startPointY = y;
			}
		}
	}
	
	bfs(startPointX, startPointY);
	
	for(int y = 0; y < h; y++) {
		for(int x = 0; x < w; x++) {
			if(visitedMap[y][x] == false && Map[y][x] == 1) {
				Map[y][x] = -1;
			}
		}
	}
	
	for(int y = 0; y < h; y++) {
		for(int x = 0; x < w; x++) {
			cout<<Map[y][x]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}