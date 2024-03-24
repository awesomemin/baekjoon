#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
string * MBTIs;
int minimunPsychologicalDistance = 987654321;

int calculatePsychologicalDistance(string A, string B) {
	int psychologicalDistance = 0;
	for(int i = 0; i < 4; i++) {
		if(A[i] != B[i]) {
			psychologicalDistance++;
		}
	}
	return psychologicalDistance;
}

void testEveryCombination(vector<string> &threeGuys, int index) {
	if(minimunPsychologicalDistance == 0) return;
	if(threeGuys.size() == 3) {
		int psychologicalDistance = 0;
		psychologicalDistance += calculatePsychologicalDistance(threeGuys[0], threeGuys[1]);
		psychologicalDistance += calculatePsychologicalDistance(threeGuys[0], threeGuys[2]);
		psychologicalDistance += calculatePsychologicalDistance(threeGuys[1], threeGuys[2]);
		if(minimunPsychologicalDistance > psychologicalDistance) {
			minimunPsychologicalDistance = psychologicalDistance;
		}
		return;
	}
	if(index >= N) return;
	
	for(int i = index; i < N; i++) {
		threeGuys.push_back(MBTIs[i]);
		testEveryCombination(threeGuys, i + 1);
		threeGuys.pop_back();
	}
	return;
}

int main(void) {
	int T; cin>>T;
	for(int TESTCASE = 0; TESTCASE < T; TESTCASE++) {
		cin>>N;
		MBTIs = new string[N];
		for(int i = 0; i < N; i++) {
			cin>>MBTIs[i];
		}
		minimunPsychologicalDistance = 987654321;
		vector<string> threeGuys;
		
		for(int i = 0; i < N; i++) {
			testEveryCombination(threeGuys, i);
		}
		
		cout<<minimunPsychologicalDistance<<endl;
		
		
		delete[] MBTIs;
	}
	
	return 0;
}