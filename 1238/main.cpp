#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int N, M, X;
vector<pair<int, int>> graph[1001];
int shortestPathToX[1001];
int dist[1001];
int answer = 0;

int dijkstraNtoX(int from, int to) {
	fill_n(dist, 1001, INF);
	dist[from] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, from});
	while(!pq.empty()) {
		int curTown = pq.top().second;
		int curDist = -pq.top().first;
		pq.pop();
		for(auto town : graph[curTown]) {
			int nextTown = town.second;
			int nextDist = town.first;
			if(dist[nextTown] > curDist + nextDist) {
				dist[nextTown] = curDist + nextDist;
				pq.push({-dist[nextTown], nextTown});
			}
		}
	}
	return dist[to];
}

void dijkstraXtoN(int start) {
	fill_n(dist, 1001, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});
	while(!pq.empty()) {
		int curTown = pq.top().second;
		int curDist = -pq.top().first;
		pq.pop();
		for(auto town : graph[curTown]) {
			int nextTown = town.second;
			int nextDist = town.first;
			if(dist[nextTown] > curDist + nextDist) {
				dist[nextTown] = curDist + nextDist;
				pq.push({-dist[nextTown], nextTown});
			}
		}
	}
}

int main(void) {
	fill_n(shortestPathToX, 1001, INF);
	fill_n(dist, 1001, INF);
	cin>>N>>M>>X;
	for(int i = 0; i < M; i++) {
		int from, to, T; cin>>from>>to>>T;
		graph[from].push_back({T, to});
	}
	
	for(int i = 1; i <= N; i++) {
		if(i == X) {
			shortestPathToX[i] = 0;
			continue;
		}
		shortestPathToX[i] = dijkstraNtoX(i, X);
	}
	
	dijkstraXtoN(X);
	
	for(int i = 1; i <= N; i++) {
		if(answer < dist[i] + shortestPathToX[i]) {
			answer = dist[i] + shortestPathToX[i];
		}
	}
	cout<<answer<<endl;
	
	return 0;
}