#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int N, M;
	cin>>N>>M;
	for(int i = 0; i < N; i++) {
		string row;
		cin>>row;
		for(int j = M - 1; j >= 0; j--) {
			cout<<row[j];
		}
		cout<<endl;
	}
	
	return 0;
}