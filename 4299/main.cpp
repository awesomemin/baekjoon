#include <iostream>
using namespace std;

int main(void) {
	int sum, sub; cin>>sum>>sub;
	if((sum + sub) % 2 != 0 || (sub - sub) % 2 != 0 || sub > sum) {
		cout<<-1<<endl;
		return 0;
	}
	int A, B;
	A = (sum + sub) / 2;
	B = (sum - sub) / 2;
	if(A > B) {
		cout<<A<<" "<<B<<endl;
	} else {
		cout<<B<<" "<<A<<endl;
	}
	
	return 0;
}