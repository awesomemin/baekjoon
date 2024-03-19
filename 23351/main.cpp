#include <iostream>
#include <vector>
using namespace std;

bool isDied(vector<int> vases) {
	for(int i = 0; i < vases.size(); i++) {
		if(vases[i] == 0) return true;
	}
	return false;
}

void water(vector<int> &vases, int &waterTarget, int waterNumber, int waterEffect) {
	while(waterNumber) {
		vases[waterTarget] += waterEffect;
		if(waterTarget == vases.size() - 1) {
			waterTarget = 0;
		} else {
			waterTarget++;
		}
		waterNumber--;
	}
}

int main(void) {
	int N, K, A, B;
	cin>>N>>K>>A>>B;
	vector<int> vases(N, K);
	int day = 0;
	int waterTarget = 0;
	while(!isDied(vases)) {
		day++;
		water(vases, waterTarget, A, B);
		for(int i = 0; i < N; i++) {
			vases[i]--;
		}
		// cout<<"Day-"<<day<<" ";
		// for(int i = 0; i < N; i++) {
		// 	cout<<vases[i]<<" ";
		// }
		// cout<<endl;
	}
	cout<<day<<endl;
	
	return 0;
}