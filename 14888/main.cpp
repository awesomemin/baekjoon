#include <iostream>
#include <vector>
using namespace std;

int N;
int numbers[11];
int pluss, minuss, multiply, divide;
vector<char> ops;
int maxVal = -1000000001;
int minVal = 1000000001;

int evaluate() {
	int result = numbers[0];
	for(int i = 1; i < N; i++) {
		if(ops[i - 1] == '+')
			result += numbers[i];
		if(ops[i - 1] == '-')
			result -= numbers[i];
		if(ops[i - 1] == '*')
			result *= numbers[i];
		if(ops[i - 1] == '/')
			result /= numbers[i];
	}
	return result;
}

void perm(int pluss, int minuss, int multiply, int divide) {
	if(pluss == 0 && minuss == 0 && multiply == 0 && divide == 0) {
		if(evaluate() > maxVal)
			maxVal = evaluate();
		if(evaluate() < minVal)
			minVal = evaluate();
		return;
	}
	if(pluss > 0) {
		ops.push_back('+');
		perm(pluss - 1, minuss, multiply, divide);
		ops.pop_back();
	}
	if(minuss > 0) {
		ops.push_back('-');
		perm(pluss, minuss - 1, multiply, divide);
		ops.pop_back();
	}
	if(multiply > 0) {
		ops.push_back('*');
		perm(pluss, minuss, multiply - 1, divide);
		ops.pop_back();
	}
	if(divide > 0) {
		ops.push_back('/');
		perm(pluss, minuss, multiply, divide - 1);
		ops.pop_back();
	}
}

int main(void) {
	cin>>N;
	for(int i = 0; i < N; i++) {
		cin>>numbers[i];
	}
	cin>>pluss>>minuss>>multiply>>divide;
	perm(pluss, minuss, multiply, divide);
	cout<<maxVal<<endl<<minVal<<endl;
	
	return 0;
}