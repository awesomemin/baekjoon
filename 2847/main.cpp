#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int levelNumber;
	cin>>levelNumber;
	
	vector<int> scores;
	for(int i = 0; i < levelNumber; i++) {
		int score;
		cin>>score;
		scores.push_back(score);
	}
	
	int answer = 0;
	
	for(int i = levelNumber - 1; i > 0; i--) {
		if(scores[i] > scores[i - 1]) {
			continue;
		}
		int scoreDifference = scores[i - 1] - scores[i];
		scores[i - 1] -= (scoreDifference + 1);
		answer += (scoreDifference + 1);
	}
	
	cout<<answer<<endl;
	
	return 0;
}