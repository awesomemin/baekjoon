#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;

deque<int> gears[4];
int K;

vector<pair<int, int>> getTargets(int t, int d) {
	vector<pair<int, int>> rtn;
	rtn.push_back({t, d});
	if(t == 0) {
		if(gears[0][2] != gears[1][6]) {
			rtn.push_back({1, -d});
			if(gears[1][2] != gears[2][6]) {
				rtn.push_back({2, d});
				if(gears[2][2] != gears[3][6]) {
					rtn.push_back({3, -d});
				}
			}
		}
	}
	
	if(t == 1) {
		if(gears[1][6] != gears[0][2]) {
			rtn.push_back({0, -d});
		}
		if(gears[1][2] != gears[2][6]) {
			rtn.push_back({2, -d});
			if(gears[2][2] != gears[3][6]) {
				rtn.push_back({3, d});
			}
		}
	}
	
	if(t == 2) {
		if(gears[2][6] != gears[1][2]) {
			rtn.push_back({1, -d});
			if(gears[1][6] != gears[0][2]) {
				rtn.push_back({0, d});
			}
		}
		if(gears[2][2] != gears[3][6]) {
			rtn.push_back({3, -d});
		}
	}
	
	if(t == 3) {
		if(gears[3][6] != gears[2][2]) {
			rtn.push_back({2, -d});
			if(gears[2][6] != gears[1][2]) {
				rtn.push_back({1, d});
				if(gears[1][6] != gears[0][2]) {
					rtn.push_back({0, -d});
				}
			}
		}
	}
	
	return rtn;
}

void spin(int target, int direction) {
	if(direction == -1) {
		gears[target].push_back(gears[target].front());
		gears[target].pop_front();
	} else if(direction == 1) {
		gears[target].push_front(gears[target].back());
		gears[target].pop_back();
	}
}

void spinGears(vector<pair<int, int>> &targets) {
	for(int i = 0; i < targets.size(); i++) {
		int target = targets[i].first;
		int direction = targets[i].second;
		spin(target, direction);
	}
}

int getScore() {
	int score = 0;
	for(int i = 0; i < 4; i++) {
		if(gears[i][0] == 1) {
			score += pow(2, i);
		}
	}
	return score;
}

int main(void) {
	for(int i = 0; i < 32; i++) {
		int temp; scanf("%1d", &temp);
		if(i < 8) {
			gears[0].push_back(temp);
		} else if(i < 16) {
			gears[1].push_back(temp);
		} else if(i < 24) {
			gears[2].push_back(temp);
		} else if(i < 32) {
			gears[3].push_back(temp);
		}
	}
	cin>>K;
	for(int i = 0; i < K; i++) {
		int t, d;
		cin>>t>>d;
		t--;
		vector<pair<int, int>> targets = getTargets(t, d);
		spinGears(targets);
	}
	
	cout<<getScore()<<endl;
	
	return 0;
}