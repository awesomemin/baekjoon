#include <iostream>
using namespace std;

int DP[1002];

int main(void) {
	DP[1] = 1;
	DP[2] = 0;
	DP[3] = 1;
	DP[4] = 1;
	
	int N; cin>>N;
	
	for(int i = 5; i <= N; i++) {
		if(DP[i - 1] == 0 || DP[i - 3] == 0 || DP[i - 4] == 0) {
			DP[i] = 1;
		} else {
			DP[i] = 0;
		}
	}
	
	if(DP[N] == 1) {
		cout<<"SK"<<endl;
	} else {
		cout<<"CY"<<endl;
	}
	
	
	return 0;
}