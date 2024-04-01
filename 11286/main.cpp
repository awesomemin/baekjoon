#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	struct cmp {
		bool operator()(int a, int b) {
			if(abs(a) > abs(b)) return true;
			else if(abs(a) == abs(b)) {
				if(a < b) return false;
				else return true;
			} else return false;
		}
	};
	
	priority_queue<int, vector<int>, cmp> pq;
	
	int N; cin>>N;
	for(int i = 0; i < N; i++) {
		int x; cin>>x;
		if(x != 0) {
			pq.push(x);
		} else {
			if(!pq.empty()) {
				cout<<pq.top()<<endl;
				pq.pop();
			} else {
				cout<<0<<endl;
			}
		}
	}
	
	return 0;
}