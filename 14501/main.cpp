#include <iostream>
#include <algorithm>
using namespace std;

int Time[25] {0};
int Pay[25] {0};
int DP[25] {0};
int N;

int main(void) {
	cin>>N;
	for(int i = 1; i <= N; i++) {
		cin>>Time[i]>>Pay[i];
	}
	
	for(int i = N; i > 0; i--) {
		if(i + Time[i] - 1 > N) {
			continue;
		}
		int maxValue = 0;
		for(int j = i + Time[i]; j <= N; j++) {
			if(DP[j] > maxValue) {
				maxValue = DP[j];
			}
		}
		DP[i] = Pay[i] + maxValue;
	}
	
	// for(int i = 1; i <= N; i++) {
	// 	cout<<DP[i]<<" ";
	// }
	
	int answer = 0;
	for(int i = 1; i <= N; i++) {
		if(answer < DP[i]) {
			answer = DP[i];
		}
	}
	cout<<answer<<endl;
	
	return 0;
}