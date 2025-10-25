#include <iostream>
using namespace std;

int main()
{
  cin.tie(NULL);
  cin.sync_with_stdio(false);
  int strategyScore;
  int managementScore;
  int technologyScore;

  int n;
  cin >> n;

  int id;
  int totalScore;
  for (int i = 0; i < n; i++)
  {
    cin >> id >> strategyScore >> managementScore >> technologyScore;
    totalScore = strategyScore + managementScore + technologyScore;
    if (strategyScore >= 11 && managementScore >= 8 && technologyScore >= 12 && totalScore >= 55)
    {
      cout << id << ' ' << totalScore << " PASS\n";
    }
    else
    {
      cout << id << ' ' << totalScore << " FAIL\n";
    }
  }

  return 0;
}