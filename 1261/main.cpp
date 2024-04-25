#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int M, N;
int maze[100][100];
int breakWallNums[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

typedef struct _point {
	int x;
	int y;
	int breakWalls = 0;
} Point;

void bfs() {
	deque<Point> dq;
	Point startPoint;
	startPoint.x = 0;
	startPoint.y = 0;
	dq.push_back(startPoint);
	while(!dq.empty()) {
		Point curPoint;
		curPoint = dq.front();
		dq.pop_front();
		if(curPoint.x == M - 1 && curPoint.y == N - 1) {
			cout<<curPoint.breakWalls<<endl;
		}
		for(int i = 0; i < 4; i++) {
			Point newPoint;
			newPoint.x = curPoint.x + dx[i];
			newPoint.y = curPoint.y + dy[i];
			newPoint.breakWalls = curPoint.breakWalls + maze[newPoint.y][newPoint.x];
			if(newPoint.x < 0 || newPoint.y < 0 || newPoint.x >= M || newPoint.y >= N) continue;
			if(breakWallNums[newPoint.y][newPoint.x] > newPoint.breakWalls) {
				breakWallNums[newPoint.y][newPoint.x] = newPoint.breakWalls;
				if(maze[newPoint.y][newPoint.x] == 1) {
					dq.push_back(newPoint);
				} else {
					dq.push_front(newPoint);
				}
			}
		}
	}
}

int main(void) {
	for(int i = 0; i < 100; i++) {
		fill_n(breakWallNums[i], 100, 987654321);
	}
	cin>>M>>N;
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			int temp;
			scanf("%1d", &maze[y][x]);
		}
	}
	
	bfs();
	
	return 0;
}