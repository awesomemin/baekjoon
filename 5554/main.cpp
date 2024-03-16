#include <iostream>
using namespace std;

int main(void) {
	int time = 0;
	for(int i = 0; i < 4; i++) {
		int tempTime;
		cin>>tempTime;
		time += tempTime;
	}
	
	int min, sec;
	
	min = time / 60;
	sec = time % 60;
	
	cout<<min<<endl<<sec<<endl;
	
	return 0;
}