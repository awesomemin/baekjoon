#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int N;
int curY = 0;
vector<pair<int, int>> queens;
bool occupiedX[15] {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
int answer = 0;

bool isPossible(int x, int y) {
	if(queens.size() == 0) return true;
	if(occupiedX[x] == true) return false;
	for(int i = 0; i < queens.size(); i++) {
		if(abs(queens[i].first - x) == abs(queens[i].second - y)) return false;
	}
	return true;
}

void bt(int y) {
	if(queens.size() == N) {
		answer++;
		return;
	}
	for(int nx = 0; nx < N; nx++) {
		if(!isPossible(nx, curY)) continue;
		occupiedX[nx] = true;
		queens.push_back({nx, curY});
		curY++;
		bt(curY);
		curY--;
		occupiedX[nx] = false;
		queens.pop_back();
	}
}

int main(void) {
	cin>>N;
	for(int x = 0; x < N; x++) {
		occupiedX[x] = true;
		queens.push_back({x, curY});
		curY++;
		bt(curY);
		curY--;
		occupiedX[x] = false;
		queens.pop_back();
	}
	cout<<answer<<endl;
	return 0;
}