#include <iostream>
using namespace std;

int main(void) {
	string str;
	cin>>str;
	int numbers[15] = {0,};
	int i = 0;
	for(auto a : str) {
		switch(a) {
			case 'A':
			case 'B':
			case 'C':
				numbers[i++] = 2;
				break;
			case 'D':
			case 'E':
			case 'F':
				numbers[i++] = 3;
				break;
			case 'G':
			case 'H':
			case 'I':
				numbers[i++] = 4;
				break;
			case 'J':
			case 'K':
			case 'L':
				numbers[i++] = 5;
				break;
			case 'M':
			case 'N':
			case 'O':
				numbers[i++] = 6;
				break;
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
				numbers[i++] = 7;
				break;
			case 'T':
			case 'U':
			case 'V':
				numbers[i++] = 8;
				break;
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
				numbers[i++] = 9;
				break;
		}
	}
	
	int sum = 0;
	
	for(auto a : numbers) {
		if(a == 0)
			break;
		sum += (a + 1);
	}
	
	cout << sum;
	
	return 0;
}