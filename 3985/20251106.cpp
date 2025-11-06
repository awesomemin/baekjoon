#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int L, N;
  cin >> L >> N;
  vector<bool> cake(L);
  int start, end;
  int mostWantedAmount = 0;
  int mostWantedPerson = 0;
  int mostCakeAmount = 0;
  int mostCakePerson = 0;
  for (int i = 1; i <= N; i++)
  {
    cin >> start >> end;
    if (end - start + 1 > mostWantedAmount)
    {
      mostWantedAmount = end - start + 1;
      mostWantedPerson = i;
    }
    int currentCakeAmount = 0;
    for (int j = start - 1; j < end; j++)
    {
      if (!cake[j])
      {
        cake[j] = true;
        currentCakeAmount++;
      }
    }
    if (currentCakeAmount > mostCakeAmount)
    {
      mostCakeAmount = currentCakeAmount;
      mostCakePerson = i;
    }
  }
  cout << mostWantedPerson << '\n'
       << mostCakePerson << '\n';
  return 0;
}