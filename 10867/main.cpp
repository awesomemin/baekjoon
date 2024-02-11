#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int num;
	set<int> s;
	set<int>::iterator iter;
	for(int i = 0; i < N; i++) {
		scanf("%d", &num);
		s.insert(num);
	}
	
	for(iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << " ";
	}
	
	return 0;
}