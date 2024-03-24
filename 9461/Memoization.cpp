#include <iostream>
using namespace std;

long long PadovanNumbers[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };

long long Padovan(int N) {
	if(PadovanNumbers[N] != 0) return PadovanNumbers[N];
	long long PadovanN = Padovan(N - 2) + Padovan(N - 3);
	PadovanNumbers[N] = PadovanN;
	return PadovanN;
}

int main(void) {
	int T; cin>>T;
	for(int TESTCASE = 0; TESTCASE < T; TESTCASE++) {
		int N; cin>>N;
		cout<<Padovan(N)<<endl;
	}
	
	return 0;
}