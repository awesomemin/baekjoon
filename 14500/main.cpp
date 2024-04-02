#include <iostream>
using namespace std;

int ** paper;
int N, M;

int shapeX[19][4] = {
	{0, 0, 0, 0},
	{0, 1, 2, 3},
	{0, 1, 0, 1},
	{0, 0, 0, 1},
	{0, 0, 0, -1},
	{0, 1, 2, 2},
	{0, 1, 2, 2},
	{0, 0, 1, 2},
	{0, 0, 1, 2},
	{0, 1, 0, 0},
	{0, 1, 1, 1},
	{0, 0, 1, 1},
	{0, 1, 1, 2},
	{0, 1, 1, 2},
	{0, 0, -1, -1},
	{0, 1, 1, 2},
	{0, 0, 1, 0},
	{0, 0, -1, 0},
	{0, 1, 1, 2}
};

int shapeY[19][4] = {
	{0, 1, 2, 3},
	{0, 0, 0, 0},
	{0, 0, 1, 1},
	{0, 1, 2, 2},
	{0, 1, 2, 2},
	{0, 0, 0, -1},
	{0, 0, 0, 1},
	{0, 1, 0, 0},
	{0, 1, 1, 1},
	{0, 0, 1, 2},
	{0, 0, 1, 2},
	{0, 1, 1, 2},
	{0, 0, -1, -1},
	{0, 0, 1, 1},
	{0, 1, 1, 2},
	{0, 0, 1, 0},
	{0, 1, 1, 2},
	{0, 1, 1, 2},
	{0, 0, -1, 0}
};

int Max = 0;

void calculateSum(int y, int x) {
	for(int i = 0; i < 19; i++) {
		int sum = 0;
		for(int j = 0; j < 4; j++) {
			if(y + shapeY[i][j] < 0 || y + shapeY[i][j] >= N || x + shapeX[i][j] < 0 || x + shapeX[i][j] >= M) {
				continue;
			}
			sum += paper[y + shapeY[i][j]][x + shapeX[i][j]];
		}
		if(sum > Max) Max = sum;
	}
}

int main(void) {
	cin>>N>>M;
	paper = new int * [N];
	for(int i = 0; i < N; i++) {
		paper[i] = new int[M];
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin>>paper[i][j];
		}
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			calculateSum(i, j);
		}
	}
	
	cout<<Max<<endl;
	
	for(int i = 0; i < N; i++) {
		delete[] paper[i];
	}
	delete[] paper;
	
	return 0;
}