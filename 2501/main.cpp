#include <iostream>
using namespace std;

int main(void) {
	int N, K; cin>>N>>K;
	int count = 0;
	for(int i = 1; i <= N; i++) {
		if(N % i == 0) {
			count++;
		}
		if(count == K) {
			cout<<i<<"\n";
			return 0;
		}
	}
	cout<<"0\n";
	return 0;
}