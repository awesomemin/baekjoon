#include <iostream>
#include <vector>
using namespace std;

int numbers[10001] = {0,};
int N, M;
vector<int> answer;

void printVec() {
	for(int num : answer) {
		cout<<num<<" ";
	}
	cout<<"\n";
}

void perm() {
	if(answer.size() == M) {
		printVec();
		return;
	}
	for(int i = 1; i <= 10000; i++) {
		if(numbers[i] > 0) {
			answer.push_back(i);
			numbers[i]--;
			perm();
			answer.pop_back();
			numbers[i]++;
		}
	}
}

int main(void) {
	cin>>N>>M;
	for(int i = 0; i < N; i++) {
		int temp; cin>>temp;
		numbers[temp]++;
	}
	
	perm();
	
	return 0;
}