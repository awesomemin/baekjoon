#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[1000][1000];
int N, M;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool visited[1000][1000] = {false,};

void setVisited() {
	for(int i = 0; i < 1000; i++) {
		fill_n(visited[i], 1000, false);
	}
}

int bfs(int sx, int sy) {
	setVisited();
	queue<vector<int>> q;
	q.push(vector<int>{sx, sy, 1, 0}); //cx, cy, distance, breakWall
	visited[sy][sx] = true;
	while(!q.empty()) {
		int cx = q.front()[0];
		int cy = q.front()[1];
		int cd = q.front()[2];
		int bw = q.front()[3];
		q.pop();
		//cout<<cx<<", "<<cy<<" / "<<cd<<" / "<<bw<<endl;
		if(sx == 0 && cx == M - 1 && cy == N - 1) return cd;
		if(sx == M - 1 && cx == 0 && cy == 0) return cd;
		
		for(int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(visited[ny][nx]) continue;
			if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if(bw == 1 && map[ny][nx] == 1) continue;
			if(map[ny][nx] == 1) {
				q.push(vector<int>{nx, ny, cd + 1, 1});
			} else {
				q.push(vector<int>{nx, ny, cd + 1, bw});
			}
			visited[ny][nx] = true;
		}
	}
	return -1;
}

int main(void) {
	cin>>N>>M;
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			scanf("%1d", &map[y][x]);
		}
	}
	
	int ans1 = bfs(0, 0);
	int ans2 = bfs(M - 1, N - 1);
	if(ans1 == -1 && ans2 == -1) {
		cout<<-1<<endl;
	} else if(ans1 == -1) {
		cout<<ans2<<endl;
	} else if(ans2 == -1) {
		cout<<ans1<<endl;
	} else {
		if(ans1 < ans2) cout<<ans1<<endl;
		else cout<<ans2<<endl;
	}
	
	return 0;
}