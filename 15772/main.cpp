#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int r1, r2, r3, r4;
int f1, f2, f3, f4;
int N;

unordered_map<string, pair<int, int>> m;

string determine(string name, int curTime) {
	if(m.find(name) == m.end()) {
		return "None";
	}
	int r = curTime - m[name].first;
	int f = m[name].second;
	if(r <= r1 && f <= f1) {
		return "New Customer";
	} else if(r > r1 && r <= r2 && f <= f1) {
		return "Promising";
	} else if(r <= r2 && f <= f3) {
		return "Potential Loyalist";
	} else if(r <= r3 && f <= f2) {
		return "About to Sleep";
	} else if(r <= r3 && f <= f3) {
		return "Need Attention";
	} else if(r <= r1 && f > f4) {
		return "Champion";
	} else if(r <= r3) {
		return "Loyal Customer";
	} else if(r > r4 && f > f4) {
		return "Can't Lose Them";
	} else if(r > r3 && f > f2) {
		return "About to Leave";
	} else if(r <= r4 && f > f1) {
		return "Hibernating";
	} else {
		return "Lost";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>r1>>r2>>r3>>r4;
	cin>>f1>>f2>>f3>>f4;
	cin>>N;
	
	for(int i = 0; i < N; i++) {
		int command; string name;
		cin>>command>>name;
		if(command == 1) {
			if(m.find(name) == m.end()) {
				m[name] = {i, 1};
			} else {
				m[name] = {i, m[name].second + 1};
			}
		} else if(command == 2) {
			cout<<determine(name, i)<<'\n';
		}
	}
	
	return 0;
}