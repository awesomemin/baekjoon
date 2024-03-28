#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int A, B;
bool visited[10001];

int D(int n) { //0
	return (n * 2) % 10000;
}

int S(int n) { //1
	if(n == 0) return 9999;
	return n - 1;
}

int L(int n) { //2
	return ((n * 10) % 10000) + (n / 1000);
}

int R(int n) { //3
	return (n / 10) + ((n % 10) * 1000);
}

void bfs(int start, int destination) {
	queue<vector<int>> q;
	vector<int> vec;
	vec.push_back(start);
	visited[start] = true;
	q.push(vec);
	
	while(!q.empty()) {
		vec.clear();
		vec = q.front();
		q.pop();
		
		//when find answer
		if(vec[0] == destination) {
			for(int i = 1; i < vec.size(); i++) {
				switch(vec[i]) {
					case 0:
						cout<<'D';
						break;
					case 1:
						cout<<'S';
						break;
					case 2:
						cout<<'L';
						break;
					case 3:
						cout<<'R';
						break;
				}
			}
			cout<<endl;
			return;
		}
		
		for(int i = 0; i < 4; i++) {
			int originalVec0 = vec[0];
			if(i == 0) {
				vec[0] = D(vec[0]);
			} else if(i == 1) {
				vec[0] = S(vec[0]);
			} else if(i == 2) {
				vec[0] = L(vec[0]);
			} else if(i == 3) {
				vec[0] = R(vec[0]);
			}
			if(visited[vec[0]]) {
				vec[0] = originalVec0;
				continue;
			}
			vec.push_back(i);
			visited[vec[0]] = true;
			q.push(vec);
			vec[0] = originalVec0;
			vec.pop_back();
		}
		
	}
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T; cin>>T;
	for(int TESTCASE = 0; TESTCASE < T; TESTCASE++) {
		cin>>A>>B;
		fill_n(visited, 10000, false);
		bfs(A, B);
	}
	
	return 0;
}