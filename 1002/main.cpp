#include <iostream>
#include <cmath>
using namespace std;

void swap(int &A, int &B) {
	int temp = A;
	A = B;
	B = temp;
}

int main(void) {
	int T; cin>>T;
	for(int TESTCASE = 0; TESTCASE < T; TESTCASE++) {
		int x1, y1, r1, x2, y2, r2;
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		if(r1 < r2) {
			swap(x1, x2);
			swap(y1, y2);
			swap(r1, r2);
		}
		double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		//cout<<"d : "<<d<<" / ";
		if(x1 == x2 && y1 == y2 && r1 == r2) { //일치한다
			cout<<-1<<endl;
			continue;
		}
		if(r1 > d + r2) { //포함하는 관계에서 안 만난다
			cout<<0<<endl;
			continue;
		}
		if(d > r1 + r2) { //서로 포함하지 않으며 안 만난다
			cout<<0<<endl;
			continue;
		}
		if(d == r1 + r2) { //외접한다
			cout<<1<<endl;
			continue;
		}
		if(r1 == d + r2) { //내접한다
			cout<<1<<endl;
			continue;
		}
		cout<<2<<endl;
	}
	
	return 0;
}