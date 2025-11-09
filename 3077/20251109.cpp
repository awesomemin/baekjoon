#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  map<string, int> map;
  for (int i = 0; i < N; i++)
  {
    string battle;
    cin >> battle;
    map[battle] = i;
  }

  vector<int> answer;
  for (int i = 0; i < N; i++)
  {
    string temp;
    cin >> temp;
    answer.push_back(map[temp]);
  }

  int score = 0;
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      if (answer[i] < answer[j])
        score++;
    }
  }
  int maxScore = N * (N - 1) / 2;
  cout << score << '/' << maxScore << '\n';

  return 0;
}