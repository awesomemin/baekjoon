#include <iostream>
using namespace std;

bool isIncluded(int * arr, int arrSize, int target) {
	for(int i = 0; i < arrSize; i++) {
		if(arr[i] == target) {
			return true;
		}
	}
	return false;
}

void getUserInput(int * arr, int arrSize) {
	for(int i = 0; i < arrSize; i++) {
		cin>>arr[i];
	}
}

int main(void) {
	int numOfPeople, numOfFriends;
	cin>>numOfPeople>>numOfFriends;
	int * wholeList = new int[numOfPeople];
	int * friendsList = new int[numOfFriends];
	
	getUserInput(wholeList, numOfPeople);
	getUserInput(friendsList, numOfFriends);
	
	int answer = numOfFriends;
	
	for(int i = 0; i < numOfFriends; i++) {
		if(isIncluded(friendsList, numOfFriends, wholeList[i])) {
			answer--;
		}
	}
	
	cout<<answer<<endl;
	return 0;
}