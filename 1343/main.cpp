#include <iostream>
#include <cstring>

int main() {
	char board[50] = { NULL, };
	std::cin >> board;
	
	int continuous_X = 0;
	int start_index = 0;
	int is_prev_X = 0;
	for(int i = 0; i < 50; i++) {
		if(board[i] == 'X' && is_prev_X == 0) {
			continuous_X++;
			start_index = i;
		} else if (board[i] == 'X') {
			continuous_X++;
		} else {
			if(continuous_X % 2 == 1) {
				std::cout << "-1\n";
				return 0;
			} else {
				if(continuous_X % 4 == 0) {
					for(int j = start_index; j < i; j++) {
						board[j] = 'A';
					}
				} else {
					for (int j = start_index; j < i; j++) {
						board[j] = 'A';
					}
				}
			}
		}
	}
	
	for(int i = 0; i < 50; i++) {
		std::cout << board[i];
	}
	
	return 0;
}