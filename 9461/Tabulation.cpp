#include <iostream>
using namespace std;

long long PadovanNumbers[101] = { 0, 1, 1, 1, };

int main(void) {
	int T; cin>>T;
	for(int TESTCASE = 0; TESTCASE < T; TESTCASE++) {
		int N; cin>>N;
		for(int i = 4; i <= N; i++) {
			PadovanNumbers[i] = PadovanNumbers[i - 3] + PadovanNumbers[i - 2];
		}
		cout<<PadovanNumbers[N]<<"\n";
	}
	
	return 0;
}