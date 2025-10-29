#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, S, R;
  cin >> N >> S >> R;
  vector<int> teams(N);
  for(int i = 0; i < S; i++) {
    int lostTeam;
    cin >> lostTeam;
    teams[lostTeam - 1]--;
  }
  for(int i = 0; i < R; i++) {
    int extraTeam;
    cin >> extraTeam;
    teams[extraTeam - 1]++;
  }
  if(teams[0] == -1 && teams[1] == 1) {
    teams[0]++;
    teams[1]--;
  }
  for(int i = 1; i < N - 1; i++) {
    if(teams[i] == -1) {
        if(teams[i - 1] == 1) {
            teams[i - 1]--;
            teams[i]++;
        } else if(teams[i + 1] == 1) {
            teams[i + 1]--;
            teams[i]++;
        }
    }
  }
  if(teams[N - 1] == -1 && teams[N - 2] == 1) {
    teams[N - 1]++;
    teams[N - 2]--;
  }

  int result = 0;
  for(int i = 0; i < N; i++) {
    if(teams[i] == -1) result++;
  }
  cout << result << '\n';
}
