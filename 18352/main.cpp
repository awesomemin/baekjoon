#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K, startCity;
vector<int> graph[300002];
bool visited[300002] = {false,};
vector<int> answers;

void bfs(int startCity) {
	queue<pair<int, int>> q;
	q.push({startCity, 0});
	visited[startCity] = true;
	while(!q.empty()) {
		int curCity = q.front().first;
		int curDist = q.front().second;
		q.pop();
		if(curDist == K) {
			answers.push_back(curCity);
			continue;
		}
		for(int city : graph[curCity]) {
			if(visited[city]) continue;
			q.push({city, curDist + 1});
			visited[city] = true;
		}
	}
}

int main(void) {
	cin>>N>>M>>K>>startCity;
	for(int i = 0; i < M; i++) {
		int A, B; cin>>A>>B;
		graph[A].push_back(B);
	}
	
	bfs(startCity);
	
	if(answers.size() == 0) {
		cout<<-1<<endl;
	} else {
		sort(answers.begin(), answers.end());
		for(int ans : answers) {
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}