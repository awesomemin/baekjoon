#include <iostream>
using namespace std;

#define INF 987654321

int n, m;
int dist[101][101];

int main(void) {
	for(int i = 0; i <= 100; i++) {
		fill_n(dist[i], 101, INF);
	}
	cin>>n>>m;
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin>>a>>b>>c;
		if(dist[a][b] > c) {
			dist[a][b] = c;
		}
	}
	
	for(int i = 0; i <= n; i++) {
		dist[i][i] = 0;
	}
	
	// for(int y = 1; y <= n; y++) {
	// 	for(int x = 1; x <= n; x++) {
	// 		if(dist[y][x] == INF) {
	// 			cout<<"INF ";
	// 		} else {
	// 			cout<<dist[y][x]<<" ";
	// 		}
	// 	}
	// 	cout<<endl;
	// }
	
	for(int stop = 1; stop <= n; stop++) {
		for(int start = 1; start <= n; start++) {
			for(int finish = 1; finish <= n; finish++) {
				if(dist[start][finish] > dist[start][stop] + dist[stop][finish]) {
					dist[start][finish] = dist[start][stop] + dist[stop][finish];
				}
			}
		}
	}
	
	for(int y = 1; y <= n; y++) {
		for(int x = 1; x <= n; x++) {
			if(dist[y][x] == INF) {
				cout<<0<<" ";
			} else {
				cout<<dist[y][x]<<" ";
			}
		}
		cout<<endl;
	}
	
	return 0;
}