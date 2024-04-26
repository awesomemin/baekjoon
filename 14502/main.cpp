#include <iostream>
#include <vector>
using namespace std;

int N, M;
int lab[8][8];
int CLab[8][8];
vector<pair<int, int>> blank;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int maxSafeZoneSize = 0;

void spread(int x, int y) {
	if(CLab[y][x] != 2) return;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
		if(CLab[ny][nx] == 0) {
			CLab[ny][nx] = 2;
			spread(nx, ny);
		}
	}
}

int main(void) {
	cin>>N>>M;
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			cin>>lab[y][x];
			if(lab[y][x] == 0) blank.push_back({x, y});
		}
	}
	
	for(int i = 0; i < blank.size() - 2; i++) {
		for(int j = i + 1; j < blank.size() - 1; j++) {
			for(int k = j + 1; k < blank.size(); k++) {
				int safeZoneSize = 0;
				for(int y = 0; y < N; y++) {
					for(int x = 0; x < M; x++) {
						CLab[y][x] = lab[y][x];
						if(x == blank[i].first && y == blank[i].second) CLab[y][x] = 1;
						if(x == blank[j].first && y == blank[j].second) CLab[y][x] = 1;
						if(x == blank[k].first && y == blank[k].second) CLab[y][x] = 1;
					}
				}
				for(int y = 0; y < N; y++) {
					for(int x = 0; x < M; x++) {
						spread(x, y);
					}
				}
				for(int y = 0; y < N; y++) {
					for(int x = 0; x < M; x++) {
						if(CLab[y][x] == 0) {
							safeZoneSize++;
						}
					}
				}
				if(maxSafeZoneSize < safeZoneSize) {
					maxSafeZoneSize = safeZoneSize;
				}
			}
		}
	}
	
	cout<<maxSafeZoneSize<<endl;
	
	return 0;
}