#include <iostream>
#include <vector>
using namespace std;

int N, M;

void permutation(vector<int> &perm) {
	if(perm.size() == M) {
		for(auto num : perm) {
			cout<<num<<" ";
		}
		cout<<endl;
		return;
	}
	for(int i = perm.back() + 1; i <= N; i++) {
		if(i > N) break;
		perm.push_back(i);
		permutation(perm);
		perm.pop_back();
	}
}

int main(void) {
	cin>>N>>M;
	vector<int> perm;
	
	for(int i = 1; i <= N; i++) {
		perm.push_back(i);
		permutation(perm);
		perm.pop_back();
	}
	
	return 0;
}