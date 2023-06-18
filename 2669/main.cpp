#include <iostream>

int main() {
	int plane[100][100];
	
	for(int y = 0; y < 100; y++) {
		for(int x = 0; x < 100; x++) {
			plane[y][x] = 0;
		}
	}
	
	for(int i = 0; i < 4; i++) {
		int x_start, x_end, y_start, y_end;
		std::cin >> x_start >> y_start >> x_end >> y_end;
		for(int y = y_start; y < y_end; y++) {
			for(int x = x_start; x < x_end; x++) {
				plane[y][x] = 1;
			}
		}
	}
	
	int sum = 0;
	for(int y = 0; y < 100; y++) {
		for(int x = 0; x < 100; x++) {
			if(plane[y][x] == 1) {
				sum++;
			}
		}
	}
	
	std::cout << sum << std::endl;
	
	return 0;
}