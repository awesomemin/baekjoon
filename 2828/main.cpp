#include <iostream>
using namespace std;

int main(void) {
	int N, M, J;
	cin>>N>>M>>J;
	int answer = 0;
	int left = 1;
	int right = M;
	for(int i = 0; i < J; i++) {
		int applePosition;
		cin>>applePosition;
		if(applePosition >= left && applePosition <= right) {
			continue;
		} else if (applePosition < left) {
			int requiredMoveDistance = left - applePosition;
			left -= requiredMoveDistance;
			right -= requiredMoveDistance;
			answer += requiredMoveDistance;
		} else if (applePosition > right) {
			int requiredMoveDistance = applePosition - right;
			left += requiredMoveDistance;
			right += requiredMoveDistance;
			answer += requiredMoveDistance;
		}
	}
	cout<<answer<<endl;
	return 0;
}