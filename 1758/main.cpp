#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int peopleNum;
	cin>>peopleNum;
	vector<long long> tips;
	for(int i = 0; i < peopleNum; i++) {
		long long tip;
		cin>>tip;
		tips.push_back(tip);
	}
	sort(tips.rbegin(), tips.rend());
	long long answer = 0;
	for(int i = 0; i < peopleNum; i++) {
		if(tips[i] - i >= 0) {
			answer += (tips[i] - i);
		}
	}
	cout<<answer<<endl;
	return 0;
}