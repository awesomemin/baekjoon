#include <iostream>
#include <vector>
using namespace std;

void Hanoi(int n, int from, int drop, int to) {
	if(n == 1) {
		cout<<from<<" "<<to<<"\n";
		return;
	}
	
	Hanoi(n - 1, from, to, drop);
	cout<<from<<" "<<to<<"\n";
	Hanoi(n - 1, drop, from, to);
}

void mul2(vector<int> &count) {
	int carry = 0;
	for(int digit = count.size() - 1; digit >= 0; digit--) {
		count[digit] = (count[digit] * 2) + carry;
		carry = 0;
		
		if(digit == 0 && count[digit] >= 10) {
			count[digit] = count[digit] % 10;
			count.insert(count.begin(), 1);
		} else if(count[digit] >= 10) {
			count[digit] = count[digit] % 10;
			carry = 1;
		}
	}
}

void plus1(vector<int> &count) {
	int carry = 0;
	for(int digit = count.size() - 1; digit >= 0; digit--) {
		count[digit] = count[digit] + 1 + carry;
		carry = 0;
		
		if(digit == 0 && count[digit] >= 10) {
			count[digit] = count[digit] % 10;
			count.insert(count.begin(), 1);
		} else if(count[digit] >= 10) {
			count[digit] = count[digit] % 10;
			carry = 1;
		} else {
			break;
		}
	}
}

void printCount(vector<int> &count) {
	for(auto num : count) {
		cout<<num;
	}
	cout<<"\n";
}

int main(void) {
	int N; cin>>N;
	
	vector<int> count = {0};
	for(int i = 0; i < N; i++) {
		mul2(count);
		plus1(count);
	}
	printCount(count);
	
	if(N <= 20) {
		Hanoi(N, 1, 2, 3);
	}
	return 0;
}