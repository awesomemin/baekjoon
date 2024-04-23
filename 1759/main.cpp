#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> chars;
vector<char> ans;

int countVowel(vector<char> vec) {
	int vowelNum = 0;
	for(int i = 0; i < vec.size(); i++) {
		if(vec[i] == 'a' ||
		   vec[i] == 'e' ||
		   vec[i] == 'i' ||
		   vec[i] == 'o' ||
		   vec[i] == 'u')
			vowelNum++;
	}
	return vowelNum;
}

int countConsonant(vector<char> vec) {
	int consonantNum = 0;
	for(int i = 0; i < vec.size(); i++) {
		if(vec[i] != 'a' &&
		   vec[i] != 'e' &&
		   vec[i] != 'i' &&
		   vec[i] != 'o' &&
		   vec[i] != 'u')
			consonantNum++;
	}
	return consonantNum;
}

void printVector(vector<char> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout<<vec[i];
	}
	cout<<"\n";
}

void perm(vector<char> vec, int index) {
	if(vec.size() == L) {
		if(countConsonant(vec) >= 2 && countVowel(vec) >= 1) {
			printVector(vec);
		}
		return;
	}
	if(index >= C) return;
	for(int i = index + 1; i < C; i++) {
		vec.push_back(chars[i]);
		perm(vec, i);
		vec.pop_back();
	}
}

int main(void) {
	cin>>L>>C;
	for(int i = 0; i < C; i++) {
		char ch; cin>>ch;
		chars.push_back(ch);
	}
	sort(chars.begin(), chars.end());
	
	for(int i = 0; i < C; i++) {
		ans.push_back(chars[i]);
		perm(ans, i);
		ans.pop_back();
	}
	
	return 0;
}