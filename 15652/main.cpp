#include <iostream>
#include <vector>
using namespace std;

int N, M;

void makeSequence(vector<int> &seq) {
	if(seq.size() == M) {
		for(auto num : seq) {
			cout<<num<<" ";
		}
		cout<<endl;
		return;
	}
	if(seq.empty()) {
		for(int i = 1; i <= N; i++) {
			seq.push_back(i);
			makeSequence(seq);
			seq.pop_back();
		}
	} else {
		for(int i = seq.back(); i <= N; i++) {
			seq.push_back(i);
			makeSequence(seq);
			seq.pop_back();
		}
	}
}

int main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>N>>M;
	vector<int> seq;
	makeSequence(seq);
	return 0;
}