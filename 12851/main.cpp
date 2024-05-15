#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool visited[100001] = {false};
int t = 0;
int ways = 0;

void bfs() {
	queue<int> q;
	queue<int> buffer;
	q.push(N);
	visited[N] = true;
	
	while(1) {
		int curPos = q.front();
		q.pop();
		if(curPos == K)
			ways++;
		if(curPos + 1 <= 100000 && !visited[curPos + 1])
			buffer.push(curPos + 1);
		
		if(curPos - 1 >= 0 && !visited[curPos - 1])
			buffer.push(curPos - 1);
		
		if(curPos * 2 <= 100000 && !visited[curPos * 2])
			buffer.push(curPos * 2);
		
		if(q.empty()) {
			if(ways != 0) break;
			t++;
			while(!buffer.empty()) {
				q.push(buffer.front());
				visited[buffer.front()] = true;
				buffer.pop();
			}
		}
	}
}

int main(void) {
	cin>>N>>K;
	bfs();
	
	cout<<t<<endl<<ways<<endl;
	
	return 0;
}