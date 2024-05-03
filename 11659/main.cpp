#include <iostream>
using namespace std;

int sums[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin>>N>>M;
	sums[0] = 0;
	for(int i = 1; i <= N; i++) {
		int temp; cin>>temp;
		sums[i] = sums[i - 1] + temp;
	}
	for(int i = 0; i < M; i++) {
		int a, b;
		cin>>a>>b;
		cout<<sums[b] - sums[a - 1]<<'\n';
	}
	return 0;
}