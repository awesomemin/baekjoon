#include <iostream>
#include <vector>
using namespace std;

int N;
int ANSWER = 0;
int ** house;
pair<int, int> head = make_pair(1, 0);
enum State {
	HORIZONTAL,
	VERTICAL,
	DIAGONAL
};
State state = HORIZONTAL;

void dfs(pair<int, int> head, State state) {
	if(head.first == N -1 && head.second == N - 1) {
		ANSWER++;
		return;
	}
	
	if(head.first >= N || head.second >= N) {
		return;
	}
	
	if(state == HORIZONTAL) {
		//move right
		pair<int, int> newHead1 = make_pair(head.first + 1, head.second);
		State newState1 = HORIZONTAL;
		if(newHead1.first < N && newHead1.second < N) {
			if(house[newHead1.second][newHead1.first] == 1) {
				//do nothing
			} else {
				dfs(newHead1, newState1);
			}
		}
		
		//move diagonal
		pair<int, int> newHead2 = make_pair(head.first + 1, head.second + 1);
		State newState2 = DIAGONAL;
		if(newHead2.first < N && newHead2.second < N) {
			if(house[newHead2.second][newHead2.first] == 1 ||
			   house[newHead2.second - 1][newHead2.first] == 1 ||
			   house[newHead2.second][newHead2.first - 1] == 1) {
				//do nothing
			} else {
				dfs(newHead2, newState2);
			}
		}
	}
	
	else if(state == VERTICAL) {
		//move down
		pair<int, int> newHead1 = make_pair(head.first, head.second + 1);
		State newState1 = VERTICAL;
		if(newHead1.first < N && newHead1.second < N) {
			if(house[newHead1.second][newHead1.first] == 1) {
				//do nothing
			} else {
				dfs(newHead1, newState1);
			}
		}
		
		//move diagonal
		pair<int, int> newHead2 = make_pair(head.first + 1, head.second + 1);
		State newState2 = DIAGONAL;
		if(newHead2.first < N && newHead2.second < N) {
			if(house[newHead2.second][newHead2.first] == 1 ||
			   house[newHead2.second - 1][newHead2.first] == 1 ||
			   house[newHead2.second][newHead2.first - 1] == 1) {
				//do nothing
			} else {
				dfs(newHead2, newState2);
			}
		}
	}
	
	else if(state == DIAGONAL) {
		//move right
		pair<int, int> newHead1 = make_pair(head.first + 1, head.second);
		State newState1 = HORIZONTAL;
		if(newHead1.first < N && newHead1.second < N) {
			if(house[newHead1.second][newHead1.first] == 1) {
				//do nothing
			} else {
				dfs(newHead1, newState1);
			}
		}
		
		//move down
		pair<int, int> newHead2 = make_pair(head.first, head.second + 1);
		State newState2 = VERTICAL;
		if(newHead2.first < N && newHead2.second < N) {
			if(house[newHead2.second][newHead2.first] == 1) {
				//do nothing
			} else {
				dfs(newHead2, newState2);
			}
		}
		
		//move diagonal
		pair<int, int> newHead3 = make_pair(head.first + 1, head.second + 1);
		State newState3 = DIAGONAL;
		if(newHead3.first < N && newHead3.second < N) {
			if(house[newHead3.second][newHead3.first] == 1 ||
			   house[newHead3.second - 1][newHead3.first] == 1 ||
			   house[newHead3.second][newHead3.first - 1] == 1) {
				//do nothing
			} else {
				dfs(newHead3, newState3);
			}
		}
	}
}

int main(void) {
	cin>>N;
	house = new int * [N];
	for(int i = 0; i < N; i++) {
		house[i] = new int[N];
	}
	
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < N; x++) {
			cin>>house[y][x];
		}
	}
	
	dfs(head, state);
	
	cout<<ANSWER<<endl;
	
	for(int i = 0; i < N; i++) {
		delete[] house[i];
	}
	delete[] house;
	
	return 0;
}