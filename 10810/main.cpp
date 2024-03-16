#include <iostream>
using namespace std;

int main(void) {
	int N, M;
	cin>>N>>M;
	int * baskets = new int[N + 1];
	for(int t = 0; t < M; t++) {
		int i, j, k;
		cin>>i>>j>>k;
		for(int tt = i; tt <= j; tt++) {
			baskets[tt] = k;
		}
	}
	
	for(int i = 1; i <= N; i++)
		cout<<baskets[i]<<' ';
	
	cout<<endl;
	
	delete []baskets;
	
	return 0;
}