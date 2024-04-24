#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> trustTable[10001];
int maxHackNum = 0;
int curHackNum = 0;
vector<int> answers;
bool visited[10001] = {false,};

void calcHackNum(int computerNum) {
	visited[computerNum] = true;
	curHackNum++;
	for(int trustingComputer : trustTable[computerNum]) {
		if(visited[trustingComputer]) continue;
		calcHackNum(trustingComputer);
	}
}

int main(void) {
	cin>>N>>M;
	for(int i = 0; i < M; i++) {
		int trusting, trusted;
		cin>>trusting>>trusted;
		trustTable[trusted].push_back(trusting);
	}
	
	for(int i = 1; i <= N; i++) {
		fill_n(visited, 10001, false);
		curHackNum = 0;
		calcHackNum(i);
		//cout<<"curHackNum of "<<i<<" : "<<curHackNum<<endl;
		if(curHackNum > maxHackNum) {
			maxHackNum = curHackNum;
			answers.clear();
			answers.push_back(i);
		} else if(curHackNum == maxHackNum) {
			answers.push_back(i);
		}
	}
	
	// for(int i = 1; i <= N; i++) {
	// 	cout<<i<<"th computer : ";
	// 	for(auto trusting : trustTable[i]) {
	// 		cout<<trusting<<" ";
	// 	}
	// 	cout<<endl;
	// }
	
	//cout<<"MaxHackNum : "<<maxHackNum<<endl;
	sort(answers.begin(), answers.end());
	for(int i = 0; i < answers.size(); i++) {
		cout<<answers[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}