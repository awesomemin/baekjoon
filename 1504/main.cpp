#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2000000000

int N, E;
int v1, v2;
int dist[801];
int startToV1;
int startToV2;
int finishToV1;
int finishToV2;
int v1ToV2;
int answer;
vector<pair<int, int>> graph[801];

void dijkstra(int start) {
	fill_n(dist, 801, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});
	while(!pq.empty()) {
		int curV = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();
		for(int i = 0; i < graph[curV].size(); i++) {
			int nextV = graph[curV][i].second;
			int w = graph[curV][i].first;
			if(dist[nextV] > curDist + w) {
				dist[nextV] = curDist + w;
				pq.push({dist[nextV], nextV});
			}
		}
	}
}

int main(void) {
	cin>>N>>E;
	for(int i = 0; i < E; i++) {
		int a, b, c;
		cin>>a>>b>>c;
		graph[a].push_back({c, b});
		graph[b].push_back({c, a});
	}
	cin>>v1>>v2;
	
	dijkstra(1);
	startToV1 = dist[v1];
	startToV2 = dist[v2];
	
	dijkstra(N);
	finishToV1 = dist[v1];
	finishToV2 = dist[v2];
	
	dijkstra(v1);
	v1ToV2 = dist[v2];
	
	if(startToV1 == INF || startToV2 == INF || finishToV1 == INF || finishToV2 == INF || v1ToV2 == INF) {
		cout<<-1<<endl;
		exit(0);
	}
	answer = startToV1 + v1ToV2 + finishToV2;
	if(answer > startToV2 + v1ToV2 + finishToV1) {
		answer = startToV2 + v1ToV2 + finishToV1;
	}
	cout<<answer<<endl;
	
	return 0;
}