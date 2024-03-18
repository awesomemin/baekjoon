#include <iostream>
using namespace std;

void findMax(int &maxIndex, int &maxValue, int * arr, int size) {
	for(int i = 0; i < size; i++) {
		if(i == 0) {
			maxValue = arr[i];
			maxIndex = i;
		}
		if(arr[i] >= maxValue) {
			maxValue = arr[i];
			maxIndex = i;
		}
	}
}

void buyOneBallot(int buyTargetIndex, int &answer, int * vote) {
	answer++;
	vote[buyTargetIndex]--;
	vote[0]++;
}

int main(void) {
	int N;
	cin>>N;
	int * vote = new int[N];
	for(int i = 0; i < N; i++) {
		cin>>vote[i];
	}
	int maxIndex = -1;
	int maxValue;
	int answer = 0;
	
	while(maxIndex != 0) {
		findMax(maxIndex, maxValue, vote, N);
		if(maxIndex == 0)
			break;
		buyOneBallot(maxIndex, answer, vote);
	}
	
	cout<<answer<<endl;
	
	return 0;
}