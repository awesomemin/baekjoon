#include <iostream>
using namespace std;

typedef unsigned long long ull;

int T;

ull maxMoveDistance(ull n) {
	ull rtn;
	if(n % 2 == 0) {
		rtn = ((n + 1) * (n + 1) - 1) / 4;
	} else {
		rtn = ((n + 1) * (n + 1)) / 4;
	}
	return rtn;
}

int main(void) {
	cin>>T;
	for(int TESTCASE = 0; TESTCASE < T; TESTCASE++) {
		ull x, y; cin>>x>>y;
		ull distance = y - x;
		ull answer = 1;
		while(1) {
			if(distance <= maxMoveDistance(answer)) {
				cout<<answer<<"\n";
				break;
			} else {
				answer++;
			}
		}
	}
	return 0;
}