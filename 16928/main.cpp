#include <iostream>
#include <queue>
using namespace std;

int board[101];
bool visited[101] {false,};

int main(void) {
	for(int i = 0; i <= 100; i++) {
		board[i] = i;
	}
	int N, M; cin>>N>>M;
	for(int i = 0; i < N + M; i++) {
		int from, to; cin>>from>>to;
		board[from] = to;
	}
	
	int depth = 0;
	
	queue<int> q;
	q.push(1);
	q.push(-1);
	visited[1] = true;
	while(!q.empty()) {
		int curPos = q.front();
		q.pop();
		if(curPos == -1) {
			depth++;
			q.push(-1);
			continue;
		}
		if(curPos == 100) {
			break;
		}
		for(int dice = 1; dice <= 6; dice++) {
			int nextPos = board[curPos + dice];
			if(nextPos > 100) {
				continue;
			}
			if(visited[nextPos]) {
				continue;
			}
			visited[nextPos] = true;
			q.push(nextPos);
		}
	}
	cout<<depth<<endl;
	
	
	return 0;
}