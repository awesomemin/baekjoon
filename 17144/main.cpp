#include <iostream>
#include <vector>
using namespace std;

int R, C, T;
int room[51][51];
int spreadingMap[51][51]{0,};
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int upperAirPurifierPos = -1;
int lowerAirPurifierPos = -1;

void getSpreadingDirections(int r, int c, vector<int> &spreadingDirections) {
	for(int i = 0; i < 4; i++) {
		int nextR = r + dr[i];
		int nextC = c + dc[i];
		if(nextR < 0 || nextC < 0 || nextR >= R || nextC >= C || room[nextR][nextC] == -1) {
			continue;
		}
		spreadingDirections.push_back(i);
	}
}

void setSpreadingMapToZero() {
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			spreadingMap[r][c] = 0;
		}
	}
}

void makeSpreadingMap() {
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			if(room[r][c] != 0 && room[r][c] != -1) { //if there is dust
				vector<int> spreadingDirections;
				getSpreadingDirections(r, c, spreadingDirections);
				int spreadingDustAmount = room[r][c] / 5;
				int remainingDustAmount = room[r][c] - (spreadingDustAmount) * spreadingDirections.size();
				for(auto direction : spreadingDirections) {
					spreadingMap[r + dr[direction]][c + dc[direction]] += spreadingDustAmount;
				}
				room[r][c] = remainingDustAmount;
			}
		}
	}
}

void applySpreadingMap() {
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			room[r][c] += spreadingMap[r][c];
		}
	}
}

void spread() {
	setSpreadingMapToZero();
	makeSpreadingMap();
	applySpreadingMap();
}

void activateUpperAirPurifier() {
	for(int r = upperAirPurifierPos - 1; r >= 1; r--) {
		room[r][0] = room[r - 1][0];
	}
	
	for(int c = 0; c < C - 1; c++) {
		room[0][c] = room[0][c + 1];
	}
	
	for(int r = 0; r < upperAirPurifierPos; r++) {
		room[r][C - 1] = room[r + 1][C - 1];
	}
	
	for(int c = C - 1; c > 0; c--) {
		if(c == 1) {
			room[upperAirPurifierPos][c] = 0;
		} else {
			room[upperAirPurifierPos][c] = room[upperAirPurifierPos][c - 1];
		}
	}
}

void activateLowerAirPurifier() {
	for(int r = lowerAirPurifierPos + 1; r < R - 1; r++) {
		room[r][0] = room[r + 1][0];
	}
	
	for(int c = 0; c < C - 1; c++) {
		room[R - 1][c] = room[R - 1][c + 1];
	}
	
	for(int r = R - 1; r > lowerAirPurifierPos; r--) {
		room[r][C - 1] = room[r - 1][C - 1];
	}
	
	for(int c = C - 1; c > 0; c--) {
		if(c == 1) {
			room[lowerAirPurifierPos][c] = 0;
		} else {
			room[lowerAirPurifierPos][c] = room[lowerAirPurifierPos][c - 1];
		}
	}
}

void airPurifier() {
	activateUpperAirPurifier();
	activateLowerAirPurifier();
}

int countDustAmount() {
	int dust = 0;
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			if(room[r][c] != -1) {
				dust += room[r][c];
			}
		}
	}
	return dust;
}

int main(void) {
	cin>>R>>C>>T;
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			cin>>room[r][c];
			if(room[r][c] == -1 && upperAirPurifierPos == -1) {
				upperAirPurifierPos = r;
			}
			if(room[r][c] == -1 && upperAirPurifierPos != -1) {
				lowerAirPurifierPos = r;
			}
		}
	}
	
	for(int i = 0; i < T; i++) {
		spread();
		airPurifier();
	}
	
	cout<<countDustAmount()<<endl;
	
	return 0;
}