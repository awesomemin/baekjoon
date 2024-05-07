#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void) {
	int numbers[500001];
	int N; cin>>N;
	for(int i = 1; i <= N; i++) {
		cin>>numbers[i];
	}
	
	sort(numbers + 1, numbers + N + 1);
	
	unsigned long long answer = 0;
	
	for(int i = 1; i <= N; i++) {
		answer += abs(i - numbers[i]);
	}
	cout<<answer<<endl;
	
	return 0;
}