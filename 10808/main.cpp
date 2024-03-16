#include <iostream>
#include <map>
using namespace std;

int main(void) {
	string word;
	cin>>word;
	
	map<char, int> wordMap;
	
	for(int i = 0; i < word.length(); i++) {
		wordMap[word[i]]++;
	}
	
	for(char i = 97; i <= 122; i++) {
		cout<<wordMap[i]<<' ';
	}
	cout<<endl;
	
	return 0;
}