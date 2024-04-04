#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> vec;
vector<int> permutation;

void makePerm(vector<int> &permutation) {
	if(permutation.size() == M) {
		for(auto num : permutation) {
			cout<<num<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i = 0; i < N; i++) {
		int nextNum = vec[i];
		if(find(permutation.begin(), permutation.end(), nextNum) != permutation.end()) {
			continue;
		}
		permutation.push_back(nextNum);
		makePerm(permutation);
		permutation.pop_back();
	}
}

int main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>N>>M;
	for(int i = 0; i < N; i++) {
		int num; cin>>num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	
	makePerm(permutation);
	
	return 0;
}