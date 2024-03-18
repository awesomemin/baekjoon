#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
	char board[51];
	for(int i = 0; i < 51; i++) {
		board[i] = 0;
	}
	cin>>board;
	int len = strlen(board);
	char * answer = new char[len];
	for(int i = 0; i < len; i++) {
		answer[i] = 0;
	}
	int continuedX = 0;
	bool isPossible = true;
	for(int i = 0; i < len; i++) {
		if(continuedX == 4) {
			for(int j = i - 4; j < i; j++) {
				answer[j] = 'A';
			}
			continuedX = 0;
		}
		
		if(board[i] == 'X') {
			continuedX++;
		}
		
		if(board[i] == '.') {
			if(continuedX == 2) {
				for(int j = i - 2; j < i; j++) {
					answer[j] = 'B';
				}
				answer[i] = '.';
				continuedX = 0;
			} else if(continuedX == 1 || continuedX == 3) {
				isPossible = false;
				break;
			} else {
				answer[i] = '.';
			}
		}
		
		if(i == len - 1 && board[i] == 'X') {
			if(continuedX == 2) {
				for(int j = i - 1; j <= i; j++) {
					answer[j] = 'B';
				}
			} else if(continuedX == 1 || continuedX == 3) {
				isPossible = false;
				break;
			} else if(continuedX == 4) {
				for(int j = i - 3; j <= i; j++) {
					answer[j] = 'A';
				}
			}
		}
	}
	
	if(isPossible) {
		cout<<answer<<endl;
	} else {
		cout<<-1<<endl;
	}
	
	return 0;
}