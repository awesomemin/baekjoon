#include <iostream>
using namespace std;

char findMost(int A, int C, int G, int T) {
	if(A >= C && A >= G && A >= T) {
		return 'A';
	}
	if(C >= A && C >= G && C >= T) {
		return 'C';
	}
	if(G >= A && G >= C && G >= T) {
		return 'G';
	}
	if(T >= A && T >= C && T >= G) {
		return 'T';
	}
	return 'O';
}

int main(void) {
	int DNANumber, DNALength;
	cin>>DNANumber>>DNALength;
	char ** DNAs = new char*[DNANumber];
	for(int i = 0; i < DNANumber; i++) {
		char * DNA = new char[DNALength];
		cin>>DNA;
		DNAs[i] = DNA;
	}
	
	char * answerDNA = new char[DNALength];
	int hammingDistance = 0;
	
	for(int i = 0; i < DNALength; i++) {
		int A=0, C=0, G=0, T=0;
		for(int j = 0; j < DNANumber; j++) {
			if(DNAs[j][i] == 'A')
				A++;
			else if(DNAs[j][i] == 'C')
				C++;
			else if(DNAs[j][i] == 'G')
				G++;
			else if(DNAs[j][i] == 'T')
				T++;
		}
		char most = findMost(A, C, G, T);
		answerDNA[i] = most;
		if(most == 'A') {
			hammingDistance += (C + G + T);
		} else if(most == 'C') {
			hammingDistance += (A + G + T);
		} else if(most == 'G') {
			hammingDistance += (A + C + T);
		} else {
			hammingDistance += (A + C + G);
		}
	}
	
	cout<<answerDNA<<endl<<hammingDistance<<endl;
	
	return 0;
}