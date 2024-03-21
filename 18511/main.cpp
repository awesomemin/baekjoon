#include <iostream>
#include <set>
using namespace std;

bool isMadeWithinK(int target, set<int> &K) {
	bool isStarted = false;
	for(int i = 100000000; i >= 1; i /= 10) {
		if((target / i) % 10 != 0) isStarted = true;
		if(isStarted) {
			if(K.find((target/i) % 10) == K.end())
				return false;
		}
	}
	return true;
}

int main(void) {
	int N;
	int Knum;
	cin>>N>>Knum;
	set<int> K;
	for(int i = 0; i < Knum; i++) {
		int temp;
		cin>>temp;
		K.insert(temp);
	}
	for(int i = N; i > 0; i--) {
		if(isMadeWithinK(i, K)) {
			cout<<i<<endl;
			break;
		}
	}
	
	return 0;
}