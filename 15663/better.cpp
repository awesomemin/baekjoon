#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int numbers[8];
vector<int> answer;
bool isUsed[8] = {false,};

void printVec() {
	for(int num : answer) {
		cout<<num<<" ";
	}
	cout<<'\n';
}

void func() {
	if(answer.size() == M) {
		printVec();
		return;
	}
	int temp = 0;
	for(int i = 0; i < N; i++) {
		if(isUsed[i] || temp == numbers[i]) continue;
		answer.push_back(numbers[i]);
		isUsed[i] = true;
		temp = numbers[i];
		func();
		answer.pop_back();
		isUsed[i] = false;
	}
}

int main(void) {
	cin>>N>>M;
	for(int i = 0; i < N; i++) {
		cin>>numbers[i];
	}
	sort(numbers, numbers + N);
	
	func();
	
	return 0;
}