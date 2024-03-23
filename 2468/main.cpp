#include <iostream>
using namespace std;

int N;
int ** Map;
int ** convertedMap;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int safeZone;
int maxSafeZone = 0;

void convertMap(int rainLevel) {
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < N; x++) {
			if(Map[y][x] <= rainLevel) {
				convertedMap[y][x] = 0; //잠긴 곳
			} else {
				convertedMap[y][x] = 1; //안 잠긴 곳
			}
		}
	}
}

void countSafeZone(int x, int y) {
	if(x < 0 || x >= N || y < 0 || y >= N) {
		return;
	}
	if(convertedMap[y][x] == 0) {
		return;
	} else {
		convertedMap[y][x] = 0;
		for(int i = 0; i < 4; i++) {
			int nextX = x + dx[i], nextY = y + dy[i];
			countSafeZone(nextX, nextY);
		}
	}
}

int main(void) {
	cin>>N;
	Map = new int * [N];
	convertedMap = new int * [N];
	for(int i = 0; i < N; i++) {
		Map[i] = new int[N];
		convertedMap[i] = new int[N];
	}
	
	for(int y = 0; y < N; y++)
		for(int x = 0; x < N; x++)
			cin>>Map[y][x];
	
	for(int rainLevel = 0; rainLevel <= 100; rainLevel++) {
		safeZone = 0;
		convertMap(rainLevel);
		for(int y = 0; y < N; y++) {
			for(int x = 0; x < N; x++) {
				if(convertedMap[y][x] == 1) {
					countSafeZone(x, y);
					safeZone++;
				}
			}
		}
		if(safeZone > maxSafeZone) maxSafeZone = safeZone;
	}
	
	cout<<maxSafeZone<<endl;
	
	for(int i = 0; i < N; i++) {
		delete[] Map[i];
		delete[] convertedMap[i];
	}
	delete[] Map;
	delete[] convertedMap;
	
	return 0;
}