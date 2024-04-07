#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double H;
int Y;
double DP[10];

double max(double A, double B, double C) {
	double rtn = max(A, B);
	rtn = max(rtn, C);
	return rtn;
}

int main(void) {
	cin>>H>>Y;
	DP[0] = H;
	for(int i = 1; i <= Y; i++) {
		if(i >= 5) {
			DP[i] = max(floor(DP[i - 5] * 1.35), floor(DP[i - 3] * 1.2), floor(DP[i - 1] * 1.05));
		} else if(i >= 3) {
			DP[i] = max(floor(DP[i - 3] * 1.2), floor(DP[i - 1] * 1.05));
		} else {
			DP[i] = floor(DP[i - 1] * 1.05);
		}
	}
	
	cout<<DP[Y]<<endl;
	
	return 0;
}