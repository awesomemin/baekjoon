#include <iostream>
#include <vector>
using namespace std;

void printPicked(vector<int> &picked) {
	for(int i = 0; i < picked.size(); i++) {
		cout<<picked[i]<<" ";
	}
	cout<<"\n";
}

void pick(vector<int> &picked, vector<int> &Set, int toPick, int index) {
	if(toPick == 0) { printPicked(picked); return; }
	
	for(int i = index; i < Set.size(); i++) {
		picked.push_back(Set[i]);
		pick(picked, Set, toPick - 1, i + 1);
		picked.pop_back();
	}
}

int main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	while(1) {
		int k; cin>>k;
		if(k == 0) break;
		vector<int> S;
		vector<int> picked;
		for(int i = 0; i < k; i++) {
			int num; cin>>num;
			S.push_back(num);
		}
		pick(picked, S, 6, 0);
		cout<<"\n";
	}
	
	return 0;
}