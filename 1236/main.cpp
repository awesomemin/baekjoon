#include <iostream>
using namespace std;

int main(void) {
	char castle[50][50];
	int N, M;
	cin>>N>>M;
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			char ch; ch = cin.get();
			if(ch == '\n') ch = cin.get();
			castle[y][x] = ch;
		}
	}
	
	int yblank = N;
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			if(castle[y][x] == 'X') {
				yblank--;
				break;
			}
		}
	}
	
	int xblank = M;
	for(int x = 0; x < M; x++) {
		for(int y = 0; y < N; y++) {
			if(castle[y][x] == 'X') {
				xblank--;
				break;
			}
		}
	}
	
	if(xblank > yblank) {
		cout<<xblank<<endl;
	} else {
		cout<<yblank<<endl;
	}
	
	return 0;
}