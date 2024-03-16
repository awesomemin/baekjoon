#include <iostream>
using namespace std;

int main(void) {
	int date;
	cin>>date;
	
	int carNumbers[5];
	for(int i = 0; i < 5; i++) {
		cin>>carNumbers[i];
	}
	
	int result = 0;
	
	for(auto num : carNumbers) {
		if(num == date)
			result++;
	}
	
	cout<<result<<endl;
	
	return 0;
}