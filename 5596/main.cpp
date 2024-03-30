#include <iostream>
using namespace std;

int main(void) {
	int A1, A2, A3, A4, B1, B2, B3, B4;
	cin>>A1>>A2>>A3>>A4>>B1>>B2>>B3>>B4;
	(A1 + A2 + A3 + A4 > B1 + B2 + B3 + B4) ? cout<<(A1 + A2 + A3 + A4) : cout<<(B1 + B2 + B3 + B4);
	cout<<endl;
	
	return 0;
}