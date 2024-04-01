#include <iostream>
using namespace std;

void getInput(int &x, int &y, int &xMax, int &yMax) {
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	if(a <= b) {
		xMax = a;
		yMax = b;
		x = c;
		y = d;
	} else {
		xMax = b;
		yMax = a;
		x = d;
		y = c;
	}
}

int main(void) {
	int T; cin>>T;
	for(int TESTCASE = 0; TESTCASE < T; TESTCASE++) {
		bool isValid = true;
		int x, y, xMax, yMax;
		getInput(x, y, xMax, yMax);
		int curY = x;
		int answer = x;
		while(curY != y) {
			curY = curY - (yMax - xMax);
			if(curY <= 0) {
				curY = yMax + curY;
			}
			answer = answer + xMax;
			if(curY == x) {
				isValid = false;
				break;
			}
		}
		if(isValid) {
			cout<<answer<<endl;
		} else {
			cout<<-1<<endl;
		}
	}
	
	return 0;
}