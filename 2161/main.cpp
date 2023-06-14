#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> cards;
	
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cards.push(i);
	}
	
	while(!cards.empty()) {
		cout << cards.front() << " ";
		cards.pop();
		cards.push(cards.front());
		cards.pop();
	}
	
	return 0;
}