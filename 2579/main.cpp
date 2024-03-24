#include <iostream>
using namespace std;

int N;
int * stairs;
int maxScore = 0;

void step(int index = 0, int continuedStairs = 0, int score = 0) {
	if(continuedStairs == 2) return;
	if(index >= N) return;
	score += stairs[index];
	if(index == N - 1) {
		if(score > maxScore) {
			maxScore = score;
		}
		return;
	}
	step(index + 1, continuedStairs + 1, score);
	step(index + 2, 0, score);
}

int main(void) {
	cin>>N;
	stairs = new int[N];
	for(int i = 0; i < N; i++) {
		cin>>stairs[i];
	}
	
	step();
	step(1);
	
	cout<<maxScore<<endl;
	
	delete[] stairs;
	return 0;
}