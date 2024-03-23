#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ** S;
int N;
int minTeamPowerDiff = 987654321;

int evaluateTeamPower(vector<int> &team) {
	int teamPower = 0;
	for(int i = 0; i < team.size(); i++) {
		for(int j = i + 1; j < team.size(); j++) {
			teamPower += S[team[i]][team[j]];
			teamPower += S[team[j]][team[i]];
		}
	}
	return teamPower;
}

void makeTeam(vector<int> &team, int toPick) {
	if(toPick == 0) {
		vector<int> otherTeam;
		for(int i = 0; i < N; i++) {
			if(find(team.begin(), team.end(), i) == team.end())
				otherTeam.push_back(i);
		}
		int team1Power = evaluateTeamPower(team);
		int team2Power = evaluateTeamPower(otherTeam);
		int teamPowerDiff = team1Power > team2Power ? team1Power - team2Power : team2Power - team1Power;
		if(teamPowerDiff < minTeamPowerDiff) minTeamPowerDiff = teamPowerDiff;
	}
	
	for(int i = team.empty() ? 0 : team.back() + 1; i < N; i++) {
		team.push_back(i);
		makeTeam(team, toPick - 1);
		team.pop_back();
	}
}

int main(void) {
	cin>>N;
	S = new int * [N];
	for(int i = 0; i < N; i++) {
		S[i] = new int[N];
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin>>S[i][j];
		}
	}
	
	vector<int> team;
	makeTeam(team, N / 2);
	
	cout<<minTeamPowerDiff<<endl;
	
	
	
	return 0;
}