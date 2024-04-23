#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> wine;
vector<int> DP;

int max(int a, int b, int c) {
	int rtn = max(a, b);
	rtn = max(rtn, c);
	return rtn;
}

int main(void) {
	cin>>N;
	for(int i = 0; i < N; i++) {
		int temp; cin>>temp;
		wine.push_back(temp);
	}
	DP.push_back(wine[0]);
	if(N >= 2)
		DP.push_back(wine[0] + wine[1]);
	if(N >= 3)
		DP.push_back(max(wine[0] + wine[1], wine[0] + wine[2], wine[1] + wine[2]));
	if(N >= 4) {
		for(int i = 3; i < N; i++) {
			DP.push_back(max(wine[i] + wine[i - 1] + DP[i - 3], wine[i] + DP[i - 2], DP[i - 1]));
		}
	}
	cout<<DP[N - 1]<<endl;
	
	
	return 0;
}