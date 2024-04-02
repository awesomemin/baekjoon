#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ** triangle;
int Max = 0;

int dfs(int i, int j, int sum) {
	if(i == N - 1) {
		return sum + triangle[i][j];
	}
	return max(dfs(i + 1, j, sum + triangle[i][j]), dfs(i + 1, j + 1, sum + triangle[i][j]));
}

int main(void) {
	cin>>N;
	triangle = new int * [N];
	for(int i = 1; i <= N; i++) {
		triangle[i - 1] = new int[i];
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j <= i; j++) {
			cin>>triangle[i][j];
		}
	}
	
	cout<<dfs(0, 0, 0)<<endl;
	
	for(int i = 0; i < N; i++) {
		delete[] triangle[i];
	}
	delete[] triangle;
	
	return 0;
}