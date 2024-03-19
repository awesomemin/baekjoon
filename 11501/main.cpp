#include <iostream>
using namespace std;

int main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int T;
	cin>>T;
	
	for(int testCase = 0; testCase < T; testCase++) {
		int N;
		cin>>N;
		int * prices = new int[N];
		for(int i = 0; i < N; i++) {
			cin>>prices[i];
		}
		long long answer = 0;
		int maxPrice = 0;
		for(int i = N - 1; i > 0; i--) {
			if(prices[i] > maxPrice) {
				maxPrice = prices[i];
			}
			if(prices[i - 1] < maxPrice) {
				answer += maxPrice - prices[i - 1];
			}
		}
		cout<<answer<<endl;
	}
	
	return 0;
}