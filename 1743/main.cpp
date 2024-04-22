#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;
int K;
bool aisle[100][100] {false,};
bool visited[100][100] {false,};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int maxSize = 0;

int main(void) {
	cin>>N>>M>>K;
	for(int i = 0; i < K; i++) {
		int r, c; cin>>r>>c;
		aisle[r - 1][c - 1] = true;
	}
	
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			if(aisle[y][x] && !visited[y][x]) {
				//cout<<"(x, y) : ("<<x<<", "<<y<<")\n";
				int size = 0;
				queue<pair<int, int>> q;
				q.push({x, y});
				size++;
				visited[y][x] = true;
				while(!q.empty()) {
					int curX = q.front().first;
					int curY = q.front().second;
					//cout<<"curX : "<<curX<<", curY : "<<curY<<endl;
					q.pop();
					for(int i = 0; i < 4; i++) {
						int nextX = curX + dx[i];
						int nextY = curY + dy[i];
						if(nextX < 0 || nextY < 0 || nextX >= M || nextY >= N || visited[nextY][nextX]) continue;
						if(aisle[nextY][nextX]) {
							visited[nextY][nextX] = true;
							q.push({nextX, nextY});
							size++;
						}
					}
				}
				if(size > maxSize) maxSize = size;
			}
			
		}
	}
	
	cout<<maxSize<<endl;
	
	return 0;
}