#include <iostream>
using namespace std;

int maxPeople = 0;
int people = 0;

int main(void) {
	for(int i = 0; i < 4; i++) {
		int up, down;
		cin>>down>>up;
		people -= down;
		people += up;
		if(people > maxPeople) maxPeople = people;
	}
	
	cout<<maxPeople<<endl;
	
	return 0;
}