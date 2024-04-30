#include <iostream>
using namespace std;

int main(void) {
	for(int i = 0; i < 3; i++) {
		int front = 0;
		int back = 0;
		for(int j = 0; j < 4; j++) {
			int temp; cin>>temp;
			if(temp == 0) back++;
			else front++;
		}
		if(back == 1) cout<<'A'<<endl;
		else if(back == 2) cout<<'B'<<endl;
		else if(back == 3) cout<<'C'<<endl;
		else if(back == 4) cout<<'D'<<endl;
		else if(back == 0) cout<<'E'<<endl;
	}
	
	return 0;
}