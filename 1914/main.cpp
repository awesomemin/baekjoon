#include <iostream>
#include <vector>
using namespace std;

void HanoiPrint(int n, int from, int drop, int to) {
	if(n == 1) {
		cout<<from<<" "<<to<<"\n";
		return;
	}
	
	HanoiPrint(n - 1, from, to, drop);
	cout<<from<<" "<<to<<"\n";
	HanoiPrint(n - 1, drop, from, to);
}

void mul2plus1(vector<int> &count) {
	int carry = 0;
	for(int digit = count.size() - 1; digit >= 0; digit--) {
		count[digit] = count[digit] * 2;
		if(carry == 1) {
			count[digit] = count[digit] + 1;
			carry = 0;
		}
		if(digit == 0 && count[digit] >= 10) {
			count[digit] = count[digit] % 10;
			count.insert(count.begin(), 1);
		}
		if(count[digit] >= 10) {
			carry = 1;
			count[digit] = count[digit] % 10;
		}
	}
	
	int digit = count.size() - 1;
	while(1) {
		count[digit] += 1;
		if(count[digit] >= 10) {
			count[digit] = count[digit] % 10;
			digit--;
		} else {
			break;
		}
	}
}

int main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int N; cin>>N;
	
	vector<int> count(1);
	for(int i = 0; i < N; i++) {
		mul2plus1(count);
	}
	for(auto num : count) {
		cout<<num;
	}
	cout<<"\n";
	if(N <= 20)	HanoiPrint(N, 1, 2, 3);
	
	return 0;
}