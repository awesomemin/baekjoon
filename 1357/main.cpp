#include <iostream>
using namespace std;

int rev(int num) {
	int rtn = 0;
	while(num != 0) {
		rtn = (rtn * 10) + (num % 10);
		num = num / 10;
	}
	return rtn;
}

int main(void) {
	int A, B;
	cin>>A>>B;
	cout<<rev(rev(A) + rev(B))<<endl;
	
	return 0;
}