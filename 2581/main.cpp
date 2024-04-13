#include <iostream>
using namespace std;

bool isPrime(int num) {
	if(num == 1) {
		return false;
	}
	for(int i = 2; i < num; i++) {
		if(num % i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int M, N; cin>>M>>N;
	int sumOfPrimes = 0;
	int smallestPrime = 0;
	for(int number = M; number <= N; number++) {
		if(isPrime(number)) {
			if(smallestPrime == 0) {
				smallestPrime = number;
			}
			sumOfPrimes += number;
		}
	}
	
	if(sumOfPrimes == 0) {
		cout<<-1<<endl;
	} else {
		cout<<sumOfPrimes<<"\n"<<smallestPrime<<"\n";
	}
	
	return 0;
}