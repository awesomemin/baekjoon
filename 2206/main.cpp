#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[1000][1000];
int N, M;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool visited[1000][1000][2] = {false,};

int bfs() {
	queue<vector<int>> q;
	q.push(vector<int>{0, 0, 1, 0}); //cx, cy, distance, breakWall
	visited[0][0][0] = true;
	while(!q.empty()) {
		int cx = q.front()[0];
		int cy = q.front()[1];
		int cd = q.front()[2];
		int bw = q.front()[3];
		q.pop();
		//cout<<cx<<", "<<cy<<" / "<<cd<<" / "<<bw<<endl;
		if(cx == M - 1 && cy == N - 1) return cd;
		
		for(int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if(visited[ny][nx][bw]) continue;
			
			if(bw == 0 && map[ny][nx] == 1) {
				visited[ny][nx][1] = true;
				q.push(vector<int>{nx, ny, cd + 1, 1});
			} else if(map[ny][nx] == 0) {
				q.push(vector<int>{nx, ny, cd + 1, bw});
				visited[ny][nx][bw] = true;
			}
		}
	}
	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// cin>>N>>M;
	scanf("%d %d", &N, &M);
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			scanf("%1d", &map[y][x]);
		}
	}
	
	cout<<bfs()<<endl;
	
	return 0;
}