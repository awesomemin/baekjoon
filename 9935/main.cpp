#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
using namespace std;

string str;
string bomb;
bool isExploded[1000001] = {false,};
stack<pair<char, int>> st;

void explode();
void checkIsBomb();

void checkIsBomb() {
	if(st.empty()) return;
	stack<pair<char, int>> buffer;
	int i = bomb.size() - 1;
	while(i >= 0) {
		//not bomb!!
		if(st.empty()) return;
		if(st.top().first != bomb[i]) {
			while(!buffer.empty()) {
				st.push(buffer.top());
				buffer.pop();
			}
			return;
		//it is bomb!!
		} else {
			if(!st.empty())
				buffer.push(st.top());
			st.pop();
		}
		i--;
	}
	while(!buffer.empty()) {
		st.push(buffer.top());
		buffer.pop();
	}
	explode();
}

void explode() {
	for(int i = 0; i < bomb.size(); i++) {
		int index = st.top().second;
		st.pop();
		isExploded[index] = true;
	}
	if(st.empty()) return;
	checkIsBomb();
}

int main(void) {
	cin>>str>>bomb;
	for(int i = 0; i < str.size(); i++) {
		st.push({str[i], i});
		checkIsBomb();
	}
	
	bool isFRULA = true;
	for(int i = 0; i < str.size(); i++) {
		if(isExploded[i] == false) {
			isFRULA = false;
			break;
		}
	}
	
	if(isFRULA) {
		cout<<"FRULA";
	} else {
		for(int i = 0; i < str.size(); i++) {
			if(isExploded[i]) continue;
			cout<<str[i];
		}
	}
	cout<<endl;
	
	return 0;
}