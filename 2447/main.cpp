#include <iostream>
using namespace std;

void draw(int x, int y, int len, char pattern, char ** &Grid) {
	if(pattern == ' ') {
		for(int i = y; i < y + len; i++) {
			for(int j = x; j < x + len; j++) {
				Grid[i][j] = ' ';
			}
		}
		return;
	}
	if(len == 1) {
		Grid[y][x] = '*';
		return;
	}
	
	int d = len / 3;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(i == 1 && j == 1) {
				draw(x + j * d, y + i * d, d, ' ', Grid);
				continue;
			}
			draw(x + j * d, y + i * d, d, '*', Grid);
		}
	}
}

void printGrid(int N, char ** &Grid) {
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < N; x++) {
			cout<<Grid[y][x];
		}
		cout<<"\n";
	}
}

int main(void) {
	int N; cin>>N;
	
	char ** Grid = new char * [N];
	for(int i = 0; i < N; i++) {
		Grid[i] = new char[N];
	}
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < N; x++) {
			Grid[y][x] = ' ';
		}
	}
	
	draw(0, 0, N, '*', Grid);
	printGrid(N, Grid);
	
	return 0;
}