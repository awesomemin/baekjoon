#include <iostream>
using namespace std;

int main(void) {
	string file;
	getline(cin, file);
	string target;
	getline(cin, target);
	
	int result = 0;
	
	if(file.length() < target.length()) {
		cout<<0<<endl;
		return 0;
	}
	
	for(int i = 0; i < file.length() - target.length() + 1; i++) {
		if(file.substr(i,target.length()).compare(target) == 0) {
			result++;
			i += (target.length() - 1);
		}
	}
	
	cout<<result<<endl;
	
	return 0;
}