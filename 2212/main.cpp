#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, K;
	cin>>N>>K;
	set<int> sensors;
	for(int i = 0; i < N; i++) {
		int sensor;
		cin>>sensor;
		sensors.insert(sensor);
	}
	if(K >= N) {
		cout<<0<<endl;
		return 0;
	}
	vector<int> distances;
	for(auto iter = sensors.begin(); iter != --sensors.end(); iter++) {
		auto tempIter = iter;
		tempIter++;
		distances.push_back(*tempIter - *iter);
	}
	sort(distances.begin(), distances.end(), greater<>());
	for(int i = 0; i < K - 1; i++) {
		distances.erase(distances.begin());
	}
	int answer = 0;
	for(auto iter : distances) {
		answer += iter;
	}
	cout<<answer<<endl;
	return 0;
}