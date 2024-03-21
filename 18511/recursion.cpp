#include <iostream>
using namespace std;

int N, K;
int nums[3];
int answer = -1;

void find(int x) {
	if(x > N) {
		return;
	}
	if(x > answer) {
		answer = x;
	}
	for(int i = 0; i < K; i++) {
		find(x*10 + nums[i]);
	}
}

int main(void) {
	cin>>N>>K;
	for(int i = 0; i < K; i++) {
		cin>>nums[i];
	}
	find(0);
	cout<<answer<<endl;
	return 0;
}