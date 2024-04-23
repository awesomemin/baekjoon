#include <iostream>
using namespace std;

int N;
int answer;

void number(int lastDigit, int remain) {
	if(lastDigit < 0 || lastDigit >= 10) return;
	if(remain == 0) {
		answer++;
		if(answer == 1000000000) answer = 0;
		return;
	}
	number(lastDigit - 1, remain - 1);
	number(lastDigit + 1, remain + 1);
}

int main(void) {
	cin>>N;
	for(int i = 1; i <= 9; i++) {
		number(i, N);
	}
	
	return 0;
}