#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void) {
	int A, B;
	cin>>A>>B;
	int N;
	cin>>N;
	int * numbers = new int[N];
	for(int i = 0; i < N; i++) {
		cin>>numbers[i];
	}
	int smallestDiff = 987654321;
	bool isSmallestDiffFromCurrentLocation = false;
	if(N == 1) {
		smallestDiff = min(abs(B - A), abs(B - numbers[0]));
		if(smallestDiff == abs(B - A))
			isSmallestDiffFromCurrentLocation = true;
	} else {
		for(int i = 0; i < N; i++) {
			smallestDiff = min(abs(B - numbers[i]), smallestDiff);
		}
		smallestDiff = min(abs(B - A), smallestDiff);
		if(smallestDiff == abs(B - A))
			isSmallestDiffFromCurrentLocation = true;
	}
	if(isSmallestDiffFromCurrentLocation) {
		cout<<smallestDiff;
	} else {
		cout<<smallestDiff + 1;
	}
	
	return 0;
}