#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int N; cin>>N;
	cin.ignore();
	string * Arr = new string[N];
	for(int i = 0; i < N; i++) {
		getline(cin, Arr[i]);
	}
	
	for(int i = 0; i < N; i++) {
		cout<<i+1<<". "<<Arr[i]<<endl;
	}
	
	return 0;
}