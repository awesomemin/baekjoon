#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;
char battleGround[100][100];
bool visited[100][100] {false,};
int whiteTeamPower = 0;
int blueTeamPower = 0;

int teamCount;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(int x, int y, char team) {
	teamCount++;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if(visited[ny][nx]) continue;
		if(battleGround[ny][nx] != team) continue;
		visited[ny][nx] = true;
		dfs(nx, ny, team);
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
				teamCount = 0;
				visited[y][x] = true;
				dfs(x, y, 'W');
				whiteTeamPower += teamCount * teamCount;
			} else {
				teamCount = 0;
				visited[y][x] = true;
				dfs(x, y, 'B');
				blueTeamPower += teamCount * teamCount;
			}
		}
	}
	
	cout<<whiteTeamPower<<" "<<blueTeamPower<<endl;
	
	return 0;
}