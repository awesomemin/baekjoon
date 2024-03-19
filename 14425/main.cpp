#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	unordered_set<string> S;
	int N, M;
	cin>>N>>M;
	int answer = 0;
	for(int i = 0; i < N; i++) {
		string temp;
		cin>>temp;
		S.insert(temp);
	}
	for(int i = 0; i < M; i++) {
		string temp;
		cin>>temp;
		auto iter = S.find(temp);
		if(iter != S.end()) {
			answer++;
		}
	}
	cout<<answer<<endl;
	
	return 0;
}