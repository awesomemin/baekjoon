#include <iostream>
#include <algorithm>
using namespace std;

int N;

int main(void) {
	cin>>N;
	int * numbers = new int[N];
	for(int i = 0; i < N; i++) {
		cin>>numbers[i];
	}
	
	int maxLength = 2;
	
	int curIncreaseLength = 1;
	int curDecreaseLength = 1;
	
	for(int i = 1; i < N; i++) {
		if(numbers[i - 1] <= numbers[i]) {
			curIncreaseLength++;
		} else {
			maxLength = max(curIncreaseLength, maxLength);
			curIncreaseLength = 1;
		}
		
		if(numbers[i - 1] >= numbers[i]) {
			curDecreaseLength++;
		} else {
			maxLength = max(curDecreaseLength, maxLength);
			curDecreaseLength = 1;
		}
	}
	
	maxLength = max(maxLength, curIncreaseLength);
	maxLength = max(maxLength, curDecreaseLength);
	
	if(N == 1) {
		cout<<1<<endl;
	} else {
		cout<<maxLength<<endl;
	}
	
	return 0;
}