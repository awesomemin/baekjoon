#include <iostream>
#include <string>
using namespace std;

int callCount;

int recursion(string &s, int l, int r) {
	callCount++;
	if(l >= r) return 1;
	else if(s[l] != s[r]) return 0;
	else return recursion(s, l+1, r-1);
}

int isPalindrome(string &s) {
	return recursion(s, 0, s.size()-1);
}


int main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int i = 0; i < T; i++) {
		callCount = 0;
		string S;
		cin>>S;
		cout<<isPalindrome(S)<<" "<<callCount<<"\n";
	}
	return 0;
}