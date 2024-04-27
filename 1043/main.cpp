#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool whoKnowTheTruth[51] = {false,};
vector<int> party[50];
int answer = 0;

bool isTruthSeekerIncluded(int partyNum) {
	for(int people : party[partyNum]) {
		if(whoKnowTheTruth[people])
			return true;
	}
	return false;
}

int main(void) {
	cin>>N>>M;
	int K; cin>>K;
	for(int i = 0; i < K; i++) {
		int temp; cin>>temp;
		whoKnowTheTruth[temp] = true;
	}
	
	for(int i = 0; i < M; i++) {
		int partyPeople; cin>>partyPeople;
		for(int p = 0; p < partyPeople; p++) {
			int num; cin>>num;
			party[i].push_back(num);
		}
	}
	
	for(int abc = 0; abc < 55; abc++) {
		for(int i = 0; i < M; i++) {
			if(isTruthSeekerIncluded(i)) {
				for(int num : party[i]) {
					whoKnowTheTruth[num] = true;
				}
			}
		}
	}
	
	for(int i = 0; i < M; i++) {
		if(isTruthSeekerIncluded(i) == false) {
			answer++;
		}
	}
	
	cout<<answer<<endl;
	
	return 0;
}