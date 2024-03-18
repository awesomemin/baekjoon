#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	queue<int> q;
	int N, K;
	cin>>N>>K;
	queue<int> answer;
	for(int i = 1; i <= N; i++) {
		q.push(i);
	}
	int count = 0;
	while(q.size() != 0) {
		count++;
		if(count == K) {
			answer.push(q.front());
			q.pop();
			count = 0;
		} else {
			q.push(q.front());
			q.pop();
		}
	}
	
	cout<<'<';
	while(answer.size() != 0) {
		if(answer.size() == 1) {
			cout<<answer.front();
			break;
		} else {
			cout<<answer.front()<<", ";
			answer.pop();
		}
	}
	cout<<">\n";
}