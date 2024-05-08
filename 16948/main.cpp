#include <iostream>
#include <queue>
using namespace std;

int N;
bool visited[200][200];
int r1, c1, r2, c2;

int dr[] = {-2, -2, 0, 0, 2, 2};
int dc[] = {-1, 1, -2, 2, -1, 1};

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({{r1, c1}, 0});
	while(!q.empty()) {
		int curR = q.front().first.first;
		int curC = q.front().first.second;
		int curMove = q.front().second;
		q.pop();
		if(curR == r2 && curC == c2) {
			return curMove;
		}
		
		for(int i = 0; i < 6; i++) {
			int nextR = curR + dr[i];
			int nextC = curC + dc[i];
			if(visited[nextR][nextC]) continue;
			if(nextR < 0 || nextC < 0 || nextR >= N || nextC >= N) continue;
			
			q.push({{nextR, nextC}, curMove + 1});
			visited[nextR][nextC] = true;
		}
	}
	return -1;
}

int main(void) {
	cin>>N;
	cin>>r1>>c1>>r2>>c2;
	for(int i = 0; i < 200; i++) {
		fill_n(visited[i], 200, false);
	}
	
	cout<<bfs()<<endl;
	
	return 0;
}