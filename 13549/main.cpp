#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
int T[100001];

void dijkstra(int start) {
	queue<pair<int, int>> q;
	q.push({start, 0});
	while(!q.empty()) {
		int curNum = q.front().first;
		int curTime = q.front().second;
		q.pop();
		//cout<<"curNum : "<<curNum<<", curTime : "<<curTime<<endl;
		if(curNum == K) break;
		
		if(curNum * 2 <= 100000 && T[curNum * 2] > curTime) {
			T[curNum * 2] = curTime;
			q.push({curNum * 2, curTime});
		}
		
		if(curNum + 1 <= 100000 && T[curNum + 1] > curTime + 1) {
			T[curNum + 1] = curTime + 1;
			q.push({curNum + 1, curTime + 1});
		}
		
		if(curNum - 1 >= 0 && T[curNum - 1] > curTime + 1) {
			T[curNum - 1] = curTime + 1;
			q.push({curNum - 1, curTime + 1});
		}
		
	}
}

int main(void) {
	fill_n(T, 100001, 987654321);
	cin>>N>>K;
	T[N] = 0;
	
	dijkstra(N);
	
	for(int i = 0; i < 40; i++) {
		cout<<"i : "<<i<<", T[i] : "<<T[i]<<endl;
	}
	
	return 0;
}