#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	priority_queue<int, vector<int>, greater<int>> pq;
	
	int N;
	cin>>N;
	
	for(int i = 0; i < N; i++) {
		int temp;
		cin>>temp;
		pq.push(temp);
	}
	
	for(int i = 0; i < N; i++) {
		cout<<pq.top()<<endl;
		pq.pop();
	}
	
	return 0;
}