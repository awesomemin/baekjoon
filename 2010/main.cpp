#include <iostream>
using namespace std;

int main(void) {
	int N; cin>>N;
	int answer = 1;
	
	for(int i = 0; i < N; i++) {
		int plug; cin>>plug;
		answer = answer + plug - 1;
	}
	
	cout<<answer<<endl;
	
	return 0;
}