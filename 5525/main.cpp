#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int N, M;
	string S;
	cin>>N>>M;
	cin>>S;
	int answer = 0;
	
	int continuedOI = 0;
	for(int i = 0; i < M; i++) {
		if(S[i] == 'I') {
			continuedOI = 0;
			while(S[i + 1] == 'O' && S[i + 2] == 'I') {
				continuedOI++;
				if(N == continuedOI) {
					answer++;
					continuedOI--;
				}
				i += 2;
			}
		}
	}
	
	cout<<answer<<endl;
	
	return 0;
}