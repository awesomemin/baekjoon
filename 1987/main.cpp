#include <iostream>
using namespace std;

int R, C;
char board[21][21];
bool visited[26];

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int answer = 0;

int ctoi(char ch) {
	return ch - 65;
}

void findPath(int r, int c, int length) {
	if(length > answer) answer = length;
	for(int i = 0; i < 4; i++) {
		int nextR = r + dr[i];
		int nextC = c + dc[i];
		if(nextR < 0 || nextC < 0 || nextR >= R || nextC >= C) continue;
		if(visited[ctoi(board[nextR][nextC])] == true) continue;
		visited[ctoi(board[nextR][nextC])] = true;
		findPath(nextR, nextC, length + 1);
		visited[ctoi(board[nextR][nextC])] = false;
	}
}

int main(void) {
	cin>>R>>C;
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			int ch = cin.get();
			if(ch == '\n') ch = cin.get();
			board[r][c] = ch;
		}
	}
	
	visited[ctoi(board[0][0])] = true;
	findPath(0, 0, 1);
	cout<<answer<<endl;
	
	return 0;
}