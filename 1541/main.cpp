#include <iostream>
#include <string>
using namespace std;

int evaluateValue(string &formula) {
	int numPlus = 0;
	for(int i = 0; i < formula.length(); i++) {
		if(formula[i] == '+') {
			numPlus++;
		}
	}
	int * numbers = new int[numPlus + 1];
	
	string temp;
	int index = 0;
	for(int i = 0; i < formula.length(); i++) {
		if(formula[i] == '+') {
			numbers[index] = stoi(temp);
			index++;
			temp = "";
			continue;
		}
		if(i == formula.length() - 1) {
			temp += formula[i];
			numbers[index] = stoi(temp);
		}
		temp += formula[i];
	}
	
	int sum = 0;
	for(int i = 0; i < numPlus + 1; i++) {
		sum += numbers[i];
	}
	
	delete[] numbers;
	
	return sum;
}

int main(void) {
	string formula;
	cin>>formula;
	
	string chunk[50];
	
	string temp;
	int index = 0;
	for(int i = 0; i < formula.length(); i++) {
		if(formula[i] == '-') {
			chunk[index] = temp;
			index++;
			temp = "";
			continue;
		}
		if(i == formula.length() - 1) {
			temp += formula[i];
			chunk[index] = temp;
		}
		temp += formula[i];
	}
	int answer;
	for(int i = 0; i <= index; i++) {
		if(i == 0) {
			answer = evaluateValue(chunk[i]);
		} else {
			answer -= evaluateValue(chunk[i]);
		}
	}
	
	cout<<answer<<endl;
	
	return 0;
}