#include <iostream>
using namespace std;

int main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int N;
	cin>>N;
	int * arrivalTime = new int[N];
	int * checkTime = new int[N];
	for(int i = 0; i < N; i++) {
		cin>>arrivalTime[i]>>checkTime[i];
	}
	int remainingCheckTime = 0;
	int time = 0;
	int arrivedCow = 0;
	
	while(1) {
		time++;
		for(int i = 0; i < N; i++) {
			if(arrivalTime[i] == time) {
				remainingCheckTime += checkTime[i];
				arrivalTime[i] = 0;
				arrivedCow++;
			}
		}
		if(remainingCheckTime > 0) {
			remainingCheckTime--;
		}
		if(arrivedCow == N && remainingCheckTime == 0) {
			break;
		}
	}
	
	cout<<time + 1<<endl;
	
	delete []arrivalTime;
	delete []checkTime;
	return 0;
}