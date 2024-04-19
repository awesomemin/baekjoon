#include <iostream>
using namespace std;

int switches[101];
int switchNum, studentNum;

void toggle(int n) {
	if(switches[n] == 1) switches[n] = 0;
	else switches[n] = 1;
}

void man(int n) {
	int num = n;
	while(num <= switchNum) {
		toggle(num);
		num = num + n;
	}
}

void woman(int n) {
	toggle(n);
	int left = n - 1;
	int right = n + 1;
	while(1) {
		if(left <= 0 || right > switchNum) break;
		if(switches[left] == switches[right]) {
			toggle(left);
			toggle(right);
			left--; right++;
		} else {
			break;
		}
	}
}

int main(void) {
	cin>>switchNum;
	for(int i = 1; i <= switchNum; i++) {
		cin>>switches[i];
	}
	cin>>studentNum;
	for(int i = 0; i < studentNum; i++) {
		int sex, num;
		cin>>sex>>num;
		if(sex == 1) {
			man(num);
		} else {
			woman(num);
		}
	}
	
	for(int i = 1; i <= switchNum; i++) {
		cout<<switches[i]<<" ";
		if(i % 20 == 0) cout<<"\n";
	}
	
	return 0;
}