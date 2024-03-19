#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N;
	cin>>N;
	vector<pair<int, int>> cows;
	for(int i = 0; i < N; i++) {
		int at, ct;
		cin>>at>>ct;
		pair<int, int> cow(at, ct);
		cows.push_back(cow);
	}
	
	sort(cows.begin(), cows.end());
	
	int time;
	
	for(int i = 0; i < N; i++) {
		if(i == 0) {
			time = cows[i].first + cows[i].second;
			continue;
		}
		if(cows[i].first >= time) {
			time = cows[i].first + cows[i].second;
		} else {
			time = time + cows[i].second;
		}
	}
	
	cout<<time<<endl;
	
	return 0;
}