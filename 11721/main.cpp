#include <iostream>
using namespace std;

int main(void) {
	string str;
	cin>>str;
	
	int count = 0;
	
	for(auto ch : str) {
		cout<<ch;
		count++;
		if(count == 10) {
			cout<<endl;
			count = 0;
		}
	}
	cout<<endl;
	
	return 0;
}