#include <iostream>
using namespace std;

void calculateWorkTime(int startH, int startM, int startS, int finishH, int finishM, int finishS) {
	int answerH, answerM, answerS = 0;
	while(startH != finishH || startM != finishM || startS != finishS) {
		startS++;
		answerS++;
		if(startS == 60) {
			startS = 0;
			startM++;
		}
		if(startM == 60) {
			startM = 0;
			startH++;
		}
	}
	
	answerH = answerS / 3600;
	answerS = answerS % 3600;
	answerM = answerS / 60;
	answerS = answerS % 60;
	
	cout<<answerH<<" "<<answerM<<" "<<answerS<<endl;
}

int main(void) {
	for(int i = 0; i < 3; i++) {
		int startH, startM, startS, finishH, finishM, finishS;
		cin>>startH>>startM>>startS>>finishH>>finishM>>finishS;
		calculateWorkTime(startH, startM, startS, finishH, finishM, finishS);
	}

	
	
	return 0;
}