#include <iostream>
#include <map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	map<string, bool, greater<string>> comp;
	int n;
	cin>>n;
	for(int i = 0; i < n; i++) {
		string name, status;
		cin>>name>>status;
		if(status.compare("enter") == 0) {
			comp.insert({name, true});
		} else {
			comp.erase(name);
		}
	}
	
	for(auto a : comp) {
		cout << a.first << "\n";
	}
	
	return 0;
}