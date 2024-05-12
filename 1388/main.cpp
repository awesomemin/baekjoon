#include <iostream>
using namespace std;

char floor[50][50];
bool visited[50][50] = {false};
int answer = 0;
int N, M;

void dfs(int x, int y) {
	if(visited[y][x] == false) {
		answer++;
	}
	visited[y][x] = true;
	
	int nx, ny;
	if(floor[y][x] == '-') {
		nx = x - 1;
		ny = y;
		if(nx >= 0 && visited[ny][nx] == false && floor[ny][nx] == floor[y][x]) {
			visited[ny][nx] = true;
			dfs(nx, ny);
		}

		nx = x + 1;
		ny = y;
		if(nx < M && visited[ny][nx] == false && floor[ny][nx] == floor[y][x]) {
			visited[ny][nx] = true;
			dfs(nx, ny);
		}
	}
	
	if(floor[y][x] == '|') {
		nx = x;
		ny = y - 1;
		if(ny >= 0 && visited[ny][nx] == false && floor[ny][nx] == floor[y][x]) {
			visited[ny][nx] = true;
			dfs(nx, ny);
		}

		nx = x;
		ny = y + 1;
		if(ny < N && visited[ny][nx] == false && floor[ny][nx] == floor[y][x]) {
			visited[ny][nx] = true;
			dfs(nx, ny);
		}
	}
}

int main(void) {
	cin>>N>>M;
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			char temp; temp = cin.get();
			if(temp == '\n') temp = cin.get();
			floor[y][x] = temp;
		}
	}
	
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			dfs(x, y);
		}
	}
	
	cout<<answer<<endl;
	
	return 0;
}