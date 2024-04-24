#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;
char battleGround[100][100];
bool visited[100][100] {false,};
int whiteTeamPower = 0;
int blueTeamPower = 0;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int x, int y, char team) {
	queue<pair<int, int>> q;
	int teamNumber = 1;
	q.push({x, y});
	visited[y][x] = true;
	while(!q.empty()) {
		int cx, cy;
		cx = q.front().first;
		cy = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int nx, ny;
			nx = cx + dx[i];
			ny = cy + dy[i];
			if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if(visited[ny][nx]) continue;
			if(battleGround[ny][nx] != team) continue;
			q.push({nx, ny});
			visited[ny][nx] = true;
			teamNumber++;
		}
	}
	if(team == 'W') {
		whiteTeamPower += teamNumber * teamNumber;
	} else {
		blueTeamPower += teamNumber * teamNumber;
	}
}

int main(void) {
	cin>>N>>M;
	for(int y = 0; y < M; y++) {
		for(int x = 0; x < N; x++) {
			char temp; temp = cin.get();
			if(temp == '\n') temp = cin.get();
			battleGround[y][x] = temp;
		}
	}
	
	for(int y = 0; y < M; y++) {
		for(int x = 0; x < N; x++) {
			if(visited[y][x]) continue;
			if(battleGround[y][x] == 'W') {
				bfs(x, y, 'W');
			} else {
				bfs(x, y, 'B');
			}
		}
	}
	
	cout<<whiteTeamPower<<" "<<blueTeamPower<<endl;
	
	return 0;
}