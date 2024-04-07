#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N, M;
int City[50][50];
int bhcNumber, homeNumber;
vector<pair<int, int>> bhc;
vector<pair<int, int>> home;
vector<int> chickenDistances[50];
vector<int> selectedBHC;
int minCityCD = 987654321;

int calcCityCD(vector<int> &selectedBHC) {
	int cityCD = 0;
	for(int h = 0; h < homeNumber; h++) {
		int homeMinCD = 987654321;
		for(int c = 0; c < selectedBHC.size(); c++) {
			homeMinCD = min(homeMinCD, chickenDistances[selectedBHC[c]][h]);
		}
		cityCD += homeMinCD;
	}
	return cityCD;
}

void select(vector<int> &selectedBHC) {
	if(selectedBHC.size() == M) {
		//찾았다!
		minCityCD = min(minCityCD, calcCityCD(selectedBHC));
		return;
	}
	if(!selectedBHC.empty() && selectedBHC.back() >= bhcNumber) {
		return;
	}
	if(selectedBHC.empty()) {
		for(int i = 0; i < bhcNumber; i++) {
			selectedBHC.push_back(i);
			select(selectedBHC);
			selectedBHC.pop_back();
		}
	} else {
		for(int i = selectedBHC.back() + 1; i < bhcNumber; i++) {
			selectedBHC.push_back(i);
			select(selectedBHC);
			selectedBHC.pop_back();
		}
	}
}

int main(void) {
	cin>>N>>M;
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < N; x++) {
			cin>>City[y][x];
			if(City[y][x] == 1) {
				home.push_back(make_pair(x, y));
			} else if(City[y][x] == 2) {
				bhc.push_back(make_pair(x, y));
			}
		}
	}
	
	bhcNumber = bhc.size();
	homeNumber = home.size();
	
	for(int i = 0; i < bhcNumber; i++) {
		for(int h = 0; h < homeNumber; h++) {
			int cd = abs(home[h].first - bhc[i].first) + abs(home[h].second - bhc[i].second);
			chickenDistances[i].push_back(cd);
		}
	}
	
	select(selectedBHC);
	
	cout<<minCityCD<<endl;
	
	return 0;
}