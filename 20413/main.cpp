#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin>>N;
	int s, g, p, d;
	cin>>s>>g>>p>>d;
	char * tier = new char[N];
	for(int i = 0; i < N; i++) {
		cin>>tier[i];
	}
	int prevMonthPayment = 0;
	int thisMonthPayment = 0;
	int answer = 0;
	for(int i = 0; i < N; i++) {
		prevMonthPayment = thisMonthPayment;
		if(tier[i] == 'B') {
			thisMonthPayment = s - prevMonthPayment - 1;
		} else if(tier[i] == 'S') {
			thisMonthPayment = g - prevMonthPayment - 1;
		} else if(tier[i] == 'G') {
			thisMonthPayment = p - prevMonthPayment - 1;
		} else if(tier[i] == 'P') {
			thisMonthPayment = d - prevMonthPayment - 1;
		} else {
			thisMonthPayment = d;
		}
		answer += thisMonthPayment;
	}
	cout<<answer<<endl;
	return 0;
}