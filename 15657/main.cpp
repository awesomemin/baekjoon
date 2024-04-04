#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> numbers;
vector<int> seq;

void makeSeq(vector<int> &seq) {
	if(seq.size() == M) {
		for(auto num : seq) {
			cout<<num<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i = 0; i < N; i++) {
		int nextNum = numbers[i];
		if(!seq.empty() && nextNum < seq.back()) continue;
		seq.push_back(numbers[i]);
		makeSeq(seq);
		seq.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin>>N>>M;
	for(int i = 0; i < N; i++) {
		int num; cin>>num;
		numbers.push_back(num);
	}
	sort(numbers.begin(), numbers.end());
	
	makeSeq(seq);
	
	return 0;
}