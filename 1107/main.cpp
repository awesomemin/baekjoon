#include <iostream>
#include <cstdlib>
#include <set>
using namespace std;

set<int> btn;

bool isMadeOfPossibleBtns(int num) {
	bool isPossible = true;
	while(isPossible) {
		int n = num % 10;
		if(btn.count(n) == 0) {
			isPossible = false;
			break;
		}
		num = num / 10;
		if(num == 0) break;
	}
	
	return isPossible;
}

int calculateDigit(int num) {
	if(num == 0) return 1;
	int digit = 0;
	while(num != 0) {
		num = num / 10;
		digit++;
	}
	return digit;
}

int main(void) {
	for(int i = 0; i < 10; i++) {
		btn.insert(i);
	}
	int targetChanel; cin>>targetChanel;
	int M; cin>>M;
	for(int i = 0; i < M; i++) {
		int brokenBtn; cin>>brokenBtn;
		btn.erase(btn.find(brokenBtn));
	}
	
	int onlyPlusMinusBtn = abs(targetChanel - 100);
	
	if(M == 10) {
		cout<<onlyPlusMinusBtn<<endl;
		return 0;
	}
	
	int downward, upward;
	downward = targetChanel;
	upward = targetChanel;
	int distance = 0;
	bool isDownward;
	
	while(1) {
		if(isMadeOfPossibleBtns(downward)) {
			isDownward = true;
			break;
		}
		if(isMadeOfPossibleBtns(upward)) {
			isDownward = false;
			break;
		}
		if(downward > 0) {
			downward--;
		}
		upward++;
		distance++;
	}
	
	int answer;
	
	if(isDownward) {
		answer = distance + calculateDigit(downward);
	} else {
		answer = distance + calculateDigit(upward);
	}

	if(answer > onlyPlusMinusBtn) {
		cout<<onlyPlusMinusBtn<<endl;
	} else {
		cout<<answer<<endl;
	}
	
	return 0;
}