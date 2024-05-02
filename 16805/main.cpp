#include <iostream>
using namespace std;

int N, M;
int Ws[10001];
int Es[10001];
int errors[10001];
int minErrorLeftBorder = 0;
int minError = 987654321;

int main(void) {
	cin>>N>>M;
	for(int ft= 1; ft <= M; ft++) {
		for(int pf = 1; pf <= N; pf++) {
			int ch = cin.get();
			if(ch == '\n') ch = cin.get();
			if(ch == 'W') {
				Ws[pf]++;
			} else if(ch == 'E') {
				Es[pf]++;
			}
		}
	}
	
	errors[0] = 0;
	for(int i = 1; i <= N; i++) {
		errors[0] += Ws[i];
	}
	
	minError = errors[0];
	minErrorLeftBorder = 0;
	
	for(int leftBorder = 1; leftBorder <= N; leftBorder++) {
		errors[leftBorder] = errors[leftBorder - 1] + Es[leftBorder] - Ws[leftBorder];
		if(errors[leftBorder] < minError) {
			minError = errors[leftBorder];
			minErrorLeftBorder = leftBorder;
		}
	}
	
	cout<<minErrorLeftBorder<<" "<<minErrorLeftBorder + 1<<endl;
	
	return 0;
}