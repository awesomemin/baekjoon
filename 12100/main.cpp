#include <iostream>
#include <vector>
using namespace std;

int N;
int input[20][20];
int board[20][20];
int maxBlock = 0;

int findLargestBlock() {
	int rtn = 0;
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < N; x++) {
			if(board[y][x] > rtn) {
				rtn = board[y][x];
			}
		}
	}
	return rtn;
}

void setBoard() {
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < N; x++) {
			board[y][x] = input[y][x];
		}
	}
}

void left() {
	for(int y = 0; y < N; y++) {
		vector<int> vec;
		for(int x = 0; x < N; x++) {
			if(board[y][x] == 0) continue;
			vec.push_back(board[y][x]);
		}
		if(vec.empty()) continue;
		for(int i = 0; i < vec.size() - 1; i++) {
			if(vec[i] == vec[i + 1]) {
				vec[i] = vec[i] * 2;
				vec.erase(vec.begin() + i + 1);
			}
		}
		fill_n(board[y], 20, 0);
		for(int i = 0; i < vec.size(); i++) {
			board[y][i] = vec[i];
		}
	}
}

void right() {
	for(int y = 0; y < N; y++) {
		vector<int> vec;
		for(int x = N - 1; x >= 0; x--) {
			if(board[y][x] == 0) continue;
			vec.push_back(board[y][x]);
		}
		if(vec.empty()) continue;
		for(int i = 0; i < vec.size() - 1; i++) {
			if(vec[i] == vec[i + 1]) {
				vec[i] = vec[i] * 2;
				vec.erase(vec.begin() + i + 1);
			}
		}
		fill_n(board[y], 20, 0);
		for(int i = 0; i < vec.size(); i++) {
			board[y][N - 1 - i] = vec[i];
		}
	}
}

void up() {
	for(int x = 0; x < N; x++) {
		vector<int> vec;
		for(int y = 0; y < N; y++) {
			if(board[y][x] == 0) continue;
			vec.push_back(board[y][x]);
		}
		if(vec.empty()) continue;
		for(int i = 0; i < vec.size() - 1; i++) {
			if(vec[i] == vec[i + 1]) {
				vec[i] = vec[i] * 2;
				vec.erase(vec.begin() + i + 1);
			}
		}
		for(int y = 0; y < N; y++) {
			board[y][x] = 0;
		}
		for(int i = 0; i < vec.size(); i++) {
			board[i][x] = vec[i];
		}
	}
}

void down() {
	for(int x = 0; x < N; x++) {
		vector<int> vec;
		for(int y = N - 1; y >= 0; y--) {
			if(board[y][x] == 0) continue;
			vec.push_back(board[y][x]);
		}
		if(vec.empty()) continue;
		for(int i = 0; i < vec.size() - 1; i++) {
			if(vec[i] == vec[i + 1]) {
				vec[i] = vec[i] * 2;
				vec.erase(vec.begin() + i + 1);
			}
		}
		for(int y = 0; y < N; y++) {
			board[y][x] = 0;
		}
		for(int i = 0; i < vec.size(); i++) {
			board[N - 1 - i][x] = vec[i];
		}
	}
}

int main(void) {
	cin>>N;
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < N; x++) {
			cin>>input[y][x];
		}
	}
	
	for(int a = 0; a < 4; a++) {
		for(int b = 0; b < 4; b++) {
			for(int c = 0; c < 4; c++) {
				for(int d = 0; d < 4; d++) {
					for(int e = 0; e < 4; e++) {
						setBoard();
						switch(a) {
							case 0:
								left();
								break;
							case 1:
								right();
								break;
							case 2:
								up();
								break;
							case 3:
								down();
								break;
						}
						switch(b) {
							case 0:
								left();
								break;
							case 1:
								right();
								break;
							case 2:
								up();
								break;
							case 3:
								down();
								break;
						}
						switch(c) {
							case 0:
								left();
								break;
							case 1:
								right();
								break;
							case 2:
								up();
								break;
							case 3:
								down();
								break;
						}
						switch(d) {
							case 0:
								left();
								break;
							case 1:
								right();
								break;
							case 2:
								up();
								break;
							case 3:
								down();
								break;
						}
						switch(e) {
							case 0:
								left();
								break;
							case 1:
								right();
								break;
							case 2:
								up();
								break;
							case 3:
								down();
								break;
						}
						int largetstBlock = findLargestBlock();
						if(largetstBlock > maxBlock) maxBlock = largetstBlock;
					}
				}
			}
		}
	}
	
	cout<<maxBlock<<endl;
	
	return 0;
}