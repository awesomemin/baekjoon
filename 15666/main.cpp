#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> numbers;
vector<int> answer;
vector<vector<int>> answers;

bool isAlradyInNumbers(int num) {
	for(int i = 0; i < numbers.size(); i++) {
		if(numbers[i] == num)
			return true;
	}
	return false;
}

bool isAlradyInAnswers(vector<int> ans) {
	for(int i = 0; i < answers.size(); i++) {
		if(answers[i] == ans)
			return true;
	}
	return false;
}

void printAnswer(vector<int> &answer) {
	for(auto num : answer) {
		cout<<num<<" ";
	}
	cout<<"\n";
}

void bt(vector<int> &answer) {
	if(answer.size() == M) {
		if(!isAlradyInAnswers(answer))
			printAnswer(answer);
		return;
	}
	for(int i = 0; i < numbers.size(); i++) {
		if(!answer.empty() && answer.back() > numbers[i]) {
			continue;
		}
		answer.push_back(numbers[i]);
		bt(answer);
		answer.pop_back();
	}
}

int main(void) {
	cin>>N>>M;
	for(int i = 0; i < N; i++) {
		int num; cin>>num;
		if(isAlradyInNumbers(num)) {
			continue;
		}
		numbers.push_back(num);
	}
	sort(numbers.begin(), numbers.end());
	
	bt(answer);
	
	return 0;
}