#include <iostream>
#include <vector>
using namespace std;

vector<int> sum(vector<int> &A, vector<int> &B) {
	int i = 0;
	vector<int> result;
	
	int carry = 0;
	while(i < A.size() && i < B.size()) {
		int summedDigit = A[i] + B[i] + carry;
		carry = 0;
		if(summedDigit >= 10) {
			summedDigit -= 10;
			carry = 1;
		}
		result.push_back(summedDigit);
		i++;
	}
	if(A.size() > B.size()) {
		while(i < A.size()) {
			int summedDigit = A[i] + carry;
			carry = 0;
			if(summedDigit >= 10) {
				summedDigit -= 10;
				carry = 1;
			}
			result.push_back(summedDigit);
			i++;
		}
	} else {
		while(i < B.size()) {
			int summedDigit = B[i] + carry;
			carry = 0;
			if(summedDigit >= 10) {
				summedDigit -= 10;
				carry = 1;
			}
			result.push_back(summedDigit);
			i++;
		}
	}
	if(carry == 1) {
		result.push_back(carry);
	}
	return result;
}

int main(void) {
	int N; cin>>N;
	
	vector<int> Fib[10001];
	Fib[0] = vector<int> {0};
	Fib[1] = vector<int> {1};
	for(int i = 2; i <= N; i++) {
		Fib[i] = sum(Fib[i - 1], Fib[i - 2]);
	}
	
	for(int i = Fib[N].size() - 1; i >= 0; i--) {
		cout<<Fib[N][i];
	}
	cout<<endl;
	
	return 0;
}