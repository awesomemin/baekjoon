#include <iostream>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int N, M;
int room[50][50];
int isCleanedMap[50][50];
int xPos, yPos, direction;
int cleanedArea = 0;

void operation1();
void operation2();
void operation3();

bool areAllClean() {
	for(int i = 0; i < 4; i++) {
		int nextX = xPos + dx[i];
		int nextY = yPos + dy[i];
		if(nextX < 0 || nextY < 0 || nextX >= M || nextY >= N) continue;
		if(isCleanedMap[nextY][nextX] == false) return false;
	}
	return true;
}

void goBack() {
	if(direction == 0) {
		yPos++;
		if(room[yPos][xPos] == 1) {
			cout<<cleanedArea<<endl;
			exit(0);
		}
	}
	if(direction == 1) {
		xPos--;
		if(room[yPos][xPos] == 1) {
			cout<<cleanedArea<<endl;
			exit(0);
		}
	}
	if(direction == 2) {
		yPos--;
		if(room[yPos][xPos] == 1) {
			cout<<cleanedArea<<endl;
			exit(0);
		}
	}
	if(direction == 3) {
		xPos++;
		if(room[yPos][xPos] == 1) {
			cout<<cleanedArea<<endl;
			exit(0);
		}
	}
}

void rotate() {
	direction--;
	if(direction == -1) direction = 3;
}

void operation1() {
	if(!isCleanedMap[yPos][xPos]) {
		cleanedArea++;
		isCleanedMap[yPos][xPos] = true;
	}
	operation2();
}

void operation2() {
	if(areAllClean()) {
		goBack();
		operation1();
	} else {
		operation3();
	}
}

void operation3() {
	for(int i = 0; i < 4; i++) {
		rotate();
		int nextX = xPos + dx[direction];
		int nextY = yPos + dy[direction];
		if(isCleanedMap[nextY][nextX] == false) break;
	}
	xPos = xPos + dx[direction];
	yPos = yPos + dy[direction];
	operation1();
}

void activate() {
	operation1();
}

int main(void) {
	cin>>N>>M;
	cin>>yPos>>xPos>>direction;
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			cin>>room[y][x];
			if(room[y][x] == 1) {
				isCleanedMap[y][x] = true;
			} else {
				isCleanedMap[y][x] = false;
			}
		}
	}
	
	activate();
	
	return 0;
}