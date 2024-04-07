#include <iostream>
using namespace std;

int main(void) {
	unsigned long long N; cin>>N;
	unsigned long long answer = 0;
	
	for(int i = 1; i < N; i++) {
		answer += (i + N * i);
	}
	
	cout<<answer<<endl;
	
	return 0;
}