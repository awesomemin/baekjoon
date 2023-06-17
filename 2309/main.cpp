#include <iostream>
#include <algorithm>

int main() {
	int sum = 0;
	int dwarfs[9];
	int first_fake_dwarf_index;
	int second_fake_dwarf_index;
	
	for(int i = 0; i < 9; i++) {
		std::cin >> dwarfs[i];
		sum += dwarfs[i];
	}
	
	std::sort(dwarfs, dwarfs + 9);
	
	
	for(int i = 0; i < 9; i++) {
		int sum_without_ith_dwarf = sum - dwarfs[i];
		for(int j = 0; j < 9; j++) {
			if(j == i) {
				continue;
			}
			if(sum_without_ith_dwarf - dwarfs[j] == 100) {
				first_fake_dwarf_index = i;
				second_fake_dwarf_index = j;
				goto OutOfNestedLoop;
			}
		}
	}
	
	OutOfNestedLoop:
	for(int i = 0; i < 9; i++) {
		if(i == first_fake_dwarf_index || i == second_fake_dwarf_index) {
			continue;
		} else {
			std::cout << dwarfs[i] << std::endl;
		}
	}
	
	return 0;
}