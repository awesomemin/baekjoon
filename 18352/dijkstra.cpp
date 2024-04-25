#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[300002];
bool visited[300002] = {false,};
int d[300002];
int N, M, K, X;

void dijkstra(int startCity) {
	queue<int> q;
	q.push(startCity);
	visited[startCity] = true;
	while(!q.empty()) {
		int curCity = q.front();
		q.pop();
		for(int nextCity : graph[curCity]) {
			if(visited[nextCity]) continue;
			if(d[curCity] + 1 < d[nextCity]) {
				d[nextCity] = d[curCity] + 1;
			}
			q.push(nextCity);
			visited[nextCity] = true;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill_n(d, 300002, 987654321);
	
	cin>>N>>M>>K>>X;
	d[X] = 0;
	for(int i = 0; i < M; i++) {
		int A, B; cin>>A>>B;
		graph[A].push_back(B);
	}
	
	dijkstra(X);
	
	bool isMinusOne = true;
	for(int i = 1; i <= N; i++) {
		if(d[i] == K) {
			isMinusOne = false;
			cout<<i<<endl;
		}
	}
	
	if(isMinusOne) cout<<-1<<endl;
	
	return 0;
}