#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int V, E;
int start;
vector<pair<int, int>> graph[20001];
int dist[20001];

struct cmp {
	bool operator() (pair<int, int> a, pair<int, int> b) {
		if(a.first > b.first) return true;
		else return false;
	}
};

void dijkstra(int startV) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
	q.push({0, startV});
	while(!q.empty()) {
		int w = q.top().first;
		int v = q.top().second;
		q.pop();
		if(w > dist[v]) continue;
		for(auto next : graph[v]) {
			int nw = next.first;
			int nv = next.second;
			if(dist[nv] > w + nw) {
				dist[nv] = w + nw;
				q.push({dist[nv], nv});
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill_n(dist, 20001, INF);
	cin>>V>>E;
	cin>>start;
	dist[start] = 0;
	for(int i = 0; i < E; i++) {
		int u, v, w; cin>>u>>v>>w;
		graph[u].push_back({w, v});
	}
	
	dijkstra(start);
	for(int i = 1; i <= V; i++) {
		if(dist[i] == INF) {
			cout<<"INF\n";
		} else {
			cout<<dist[i]<<"\n";
		}
	}
	
	return 0;
}