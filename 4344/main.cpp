#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

double average(vector<int> nums) {
	if(nums.empty())
		return 0;
	
	return accumulate(nums.begin(), nums.end(), 0) / nums.size();
}

int main(void) {
	int C;
	cin>>C;
	vector<int> vec;
	for(int i = 0; i < C; i++) {
		int N;
		cin>>N;
		for(int student = 0; student < N; student++) {
			int score;
			cin>>score;
			vec.push_back(score);
		}
		int avg = average(vec);	
		double count = 0;
		for(auto num : vec) {
			if(num > avg)
				count++;
		}
		printf("%.3f%%\n", (count / vec.size()) * 100);
		vec.clear();
	}
	
	return 0;
}