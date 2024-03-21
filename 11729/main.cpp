#include <iostream>
using namespace std;

void HanoiPrint(int n, int from, int drop, int to) {
	if(n == 1) {
		cout<<from<<" "<<to<<"\n";
		return;
	}
	
	HanoiPrint(n - 1, from, to, drop);
	cout<<from<<" "<<to<<"\n";
	HanoiPrint(n - 1, drop, from, to);
}

int main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int N;
	cin>>N;
	
	int count = 0;
	
	for(int i = 0; i < N; i++) {
		count = count * 2 + 1;
	}
	
	cout<<count<<"\n";
	
	HanoiPrint(N, 1, 2, 3);
	
	return 0;
}