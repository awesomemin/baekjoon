#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> tree[10001];
bool visited[10001] = {false};
int mostFarNode;
int mostFarDist = 0;

void dfs(int node, int dist) {
	if(mostFarDist < dist) {
		mostFarNode = node;
		mostFarDist = dist;
	}
	for(int i = 0; i < tree[node].size(); i++) {
		int nNode = tree[node][i].first;
		int nDist = tree[node][i].second;
		if(visited[nNode]) continue;
		visited[nNode] = true;
		dfs(nNode, dist + nDist);
	}
}

int main(void) {
	cin>>n;
	for(int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin>>a>>b>>c;
		tree[a].push_back({b, c});
		tree[b].push_back({a, c});
	}
	
	visited[1] = true;
	dfs(1, 0);
	fill_n(visited, 10001, false);
	visited[mostFarNode] = true;
	mostFarDist = 0;
	dfs(mostFarNode, 0);
	cout<<mostFarDist<<endl;
	
	return 0;
}