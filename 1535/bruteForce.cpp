#include <iostream>
using namespace std;

int N;
int HP[20];
int Joy[20];

int maxJoy = 0;

void bf(int curHP, int curJoy, int index) {
	if(curJoy > maxJoy) maxJoy = curJoy;
	for(int i = index + 1; i < N; i++) {
		if(curHP - HP[i] <= 0) {
			continue;
		}
		bf(curHP - HP[i], curJoy + Joy[i], i);
	}
}

int main(void) {
	cin>>N;
	for(int i = 0; i < N; i++) {
		cin>>HP[i];
	}
	for(int i = 0; i < N; i++) {
		cin>>Joy[i];
	}
	
	for(int i = 0; i < N; i++) {
		if(HP[i] >= 100) continue;
		bf(100 - HP[i], Joy[i], i);
	}
	
	cout<<maxJoy<<endl;
	
	return 0;
}