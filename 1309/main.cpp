#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> DP;

int main(void) {
	cin>>N;
	for(int i = 0; i < N; i++) {
		if(i == 0) {
			DP.push_back(3);
		} else if(i == 1) {
			DP.push_back(7);
		} else {
			DP.push_back((DP[i - 2] + 2 * DP[i - 1]) % 9901);
		}
	}
	cout<<DP[N - 1]<<endl;
	
	return 0;
}