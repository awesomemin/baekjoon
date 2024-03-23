#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> numbers;
int N, S;
int answer = 0;

void pickNums(vector<int> &picked, int index) {
	if(accumulate(picked.begin(), picked.end(), 0) == S && picked.size() != 0) { answer++; }
	if(index >= N) return;
	for(int i = index; i < N; i++) {
		picked.push_back(numbers[i]);
		pickNums(picked, i + 1);
		picked.pop_back();
	}
	return;
}

int main(void) {
	cin>>N>>S;
	for(int i = 0; i < N; i++) { int num; cin>>num; numbers.push_back(num); }
	
	vector<int> picked;
	pickNums(picked, 0);
	
	cout<<answer<<endl;
	
	return 0;
}