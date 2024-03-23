#include <iostream>
using namespace std;

void draw(int x, int y, int len, char ** &Grid) {
	if(len == 1) {
		Grid[y][x] = '*';
		return;
	}
	
	for(int tx = x; tx < x + len; tx++) {
		Grid[y][tx] = '*';
		Grid[y + len - 1][tx] = '*';
	}
	
	for(int ty = y; ty < y + len; ty++) {
		Grid[ty][x] = '*';
		Grid[ty][x + len - 1] = '*';
	}
	
	draw(x + 2, y + 2, len - 4, Grid);
}

void printGrid(int n, char ** &Grid) {
	for(int y = 0; y < 4*n-3; y++) {
		for(int x = 0; x < 4*n-3; x++) {
			cout<<Grid[y][x];
		}
		cout<<endl;
	}
}

int main(void) {
	int N; cin>>N;
	
	char ** Grid = new char*[4*N-3];
	for(int i = 0; i < 4*N-3; i++) {
		Grid[i] = new char[4*N-3];
	}
	
	for(int y = 0; y < 4*N-3; y++) {
		for(int x = 0; x < 4*N-3; x++) {
			Grid[y][x] = ' ';
		}
	}
	
	draw(0, 0, 4*N-3, Grid);
	
	printGrid(N, Grid);
	
	for(int i = 0; i < 4*N-3; i++) {
		delete []Grid[i];
	}
	delete []Grid;
	
	return 0;
}