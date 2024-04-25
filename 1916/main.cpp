#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> graph[1001];
int d[1001];

class cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({start, 0});
	while(!pq.empty()) {
		int curCity = pq.top().first;
		int dist = pq.top().second;
		pq.pop();
		if(d[curCity] < dist) continue;
		for(pair<int, int> next : graph[curCity]) {
			int nextCity = next.first;
			int busCost = next.second;
			if(d[nextCity] <= dist + busCost) continue;
			d[nextCity] = dist + busCost;
			pq.push({nextCity, dist + busCost});
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill_n(d, 1001, 987654321);
	cin>>N>>M;
	for(int i = 0; i < M; i++) {
		int start, end, cost;
		cin>>start>>end>>cost;
		graph[start].push_back({end, cost});
	}
	int start, end;
	cin>>start>>end;
	
	dijkstra(start);
	
	cout<<d[end]<<endl;
	
	return 0;
}