#include <iostream>
#include <queue>
using namespace std;

int N, M;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

char ** campus;
bool ** visited;

int answer = 0;

queue<pair<int, int>> q;

void bfs(int x, int y) {
	pair<int, int> p(x, y);
	q.push(p);
	
	while(!q.empty()) {
		pair<int, int> Point = q.front();
		q.pop();
		visited[Point.second][Point.first] = true;
		
		if(campus[Point.second][Point.first] == 'P') answer++;
		for(int i = 0; i < 4; i++) {
			int nextX = Point.first + dx[i], nextY = Point.second + dy[i];
			if(nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
			if(campus[nextY][nextX] == 'X') continue;
			if(visited[nextY][nextX] == true) continue;
			pair<int, int> temp(nextX, nextY);
			q.push(temp);
			visited[nextY][nextX] = true;
		}
	}
}

int main(void) {
	cin>>N>>M;
	campus = new char * [N];
	visited = new bool * [N];
	for(int i = 0; i < N; i++) {
		campus[i] = new char[M];
		visited[i] = new bool[M];
	}
	
	for(int y = 0; y < N; y++) {
		cin>>campus[y];
	}
	
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			visited[y][x] = false;
		}
	}
	
	int myPosX, myPosY;
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			if(campus[y][x] == 'I') {
				myPosX = x; myPosY = y; break;
			}
		}
	}
	
	bfs(myPosX, myPosY);
	
	if(answer == 0) cout<<"TT"<<endl;
	else cout<<answer<<endl;
	
	return 0;
}