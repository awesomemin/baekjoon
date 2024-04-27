#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int N;
int map[20][20];
int babySize = 2;
int XP = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
pair<int, int> babyPos;
vector<pair<int, int>> edibleFish;
int dist[20][20];
bool visit[20][20];
int T = 0;

void input() {
	cin>>N;
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < N; x++) {
			cin>>map[y][x];
			if(map[y][x] == 9) {
				babyPos.first = x;
				babyPos.second = y;
			}
		}
	}
}

void clearDist() {
	for(int i = 0; i < 20; i++) {
		fill_n(dist[i], 20, INF);
		fill_n(visit[i], 20, false);
	}
	dist[babyPos.second][babyPos.first] = 0;
}

void findEdibleFish() {
	edibleFish.clear();
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < N; x++) {
			if(map[y][x] < babySize && map[y][x] != 0 && dist[y][x] != INF && map[y][x] != 9) {
				edibleFish.push_back({x, y});
			}
		}
	}
}

void calcDist() {
	clearDist();
	queue<pair<int, pair<int, int>>> q;
	q.push({0, {babyPos.first, babyPos.second}});
	visit[babyPos.second][babyPos.first] = true;
	while(!q.empty()) {
		int curDist = q.front().first;
		int curX = q.front().second.first;
		int curY = q.front().second.second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if(visit[ny][nx]) continue;
			if(map[ny][nx] > babySize) continue;
			q.push({curDist + 1, {nx, ny}});
			visit[ny][nx] = true;
			dist[ny][nx] = curDist + 1;
		}
	}
}

void eatFish() {
	int minDist = INF;
	int targetFish;
	for(int i = 0; i < edibleFish.size(); i++) {
		int fishX = edibleFish[i].first;
		int fishY = edibleFish[i].second;
		if(dist[fishY][fishX] < minDist) {
			minDist = dist[fishY][fishX];
			targetFish = i;
		}
	}
	int targetX = edibleFish[targetFish].first;
	int targetY = edibleFish[targetFish].second;
	map[babyPos.second][babyPos.first] = 0;
	map[targetY][targetX] = 9;
	babyPos.first = targetX;
	babyPos.second = targetY;
	T += dist[targetY][targetX];
	XP++;
	if(XP == babySize) {
		XP = 0;
		babySize++;
	}
}

int main(void) {
	input();
	
	while(1) {
		calcDist();
		findEdibleFish();
		if(edibleFish.empty()) break;
		eatFish();
	}
	
	cout<<T<<endl;
	
	return 0;
}