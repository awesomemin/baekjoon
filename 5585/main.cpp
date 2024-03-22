#include <iostream>
using namespace std;

int main(void) {
	int price;
	cin>>price;
	
	int change = 1000 - price;
	
	int answer = 0;
	while(change != 0) {
		if(change - 500 >= 0) {
			change -= 500;
			answer++;
			continue;
		} else if(change - 100 >= 0) {
			change -= 100;
			answer++;
			continue;
		} else if(change - 50 >= 0) {
			change -= 50;
			answer++;
			continue;
		} else if(change - 10 >= 0) {
			change -= 10;
			answer++;
			continue;
		} else if(change - 5 >= 0) {
			change -= 5;
			answer++;
			continue;
		} else if (change - 1 >= 0) {
			change -= 1;
			answer++;
			continue;
		}
	}
	
	cout<<answer<<endl;
	
	return 0;
}