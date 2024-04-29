#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int n, m, r;
int items[101];
int dist[101][101];
int maxItem = 0;

void input() {
	for(int i = 0; i < 101; i++) {
		fill_n(dist[i], 101, INF);
	}
	for(int i = 0; i < 101; i++) {
		dist[i][i] = 0;
	}
	cin>>n>>m>>r;
	for(int i = 1; i <= n; i++) {
		cin>>items[i];
	}
	for(int i = 0; i < r; i++) {
		int a, b, l;
		cin>>a>>b>>l;
		dist[a][b] = l;
		dist[b][a] = l;
	}
}

void floyd() {
	for(int stop = 1; stop <= n; stop++) {
		for(int start = 1; start <= n; start++) {
			for(int finish = 1; finish <= n; finish++) {
				dist[start][finish] = min(dist[start][finish], dist[start][stop] + dist[stop][finish]);
			}
		}
	}
}

void findMaxItem() {
	for(int startCity = 1; startCity <= n; startCity++) {
		int availableItems = 0;
		for(int targetCity = 1; targetCity <= n; targetCity++) {
			if(dist[startCity][targetCity] <= m) {
				availableItems += items[targetCity];
			}
		}
		if(maxItem < availableItems) maxItem = availableItems;
	}
}

int main(void) {
	input();
	floyd();
	findMaxItem();
	cout<<maxItem<<endl;
	
	return 0;
}