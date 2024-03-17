#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(void) {
	int N, K;
	cin>>N>>K;
	map<int, vector<int>> table;
	for(int i = 0; i < N; i++) {
		int nation, gold, silver, bronze;
		cin>>nation>>gold>>silver>>bronze;
		vector<int> v;
		v.push_back(gold);
		v.push_back(silver);
		v.push_back(bronze);
		table.insert({nation, v});
	}
	
	int nationsThatBetterThanMe = 0;
	
	map<int, vector<int>> sameGoldMedal;
	for(auto iter = table.begin(); iter != table.end(); ++iter) {
		if(iter->first == K)
			continue;
		if(iter->second[0] > table[K][0]) {
			nationsThatBetterThanMe++;
			continue;
		}
		if(iter->second[0] == table[K][0]) {
			sameGoldMedal.insert({iter->first, iter->second});
		}
	}
	
	map<int, vector<int>> sameSilverMedal;
	for(auto iter = sameGoldMedal.begin(); iter != sameGoldMedal.end(); ++iter) {
		if(iter->second[1] > table[K][1]) {
			nationsThatBetterThanMe++;
			continue;
		}
		if(iter->second[1] == table[K][1]) {
			sameSilverMedal.insert({iter->first, iter->second});
		}
	}
	
	for(auto iter = sameSilverMedal.begin(); iter != sameSilverMedal.end(); ++iter) {
		if(iter->second[2] > table[K][2]) {
			nationsThatBetterThanMe++;
		}
	}
	
	cout<<nationsThatBetterThanMe + 1<<endl;
	
	return 0;
}