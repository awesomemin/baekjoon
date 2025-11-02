#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int const MAX_LEVEL = 250;
  int const XP_TO_LEVEL_UP = 100;
  int A, B, C, S, V, L;
  cin >> A >> B >> C >> S >> V >> L;
  int currentXP = 0;
  int requiredXP = (MAX_LEVEL - L) * XP_TO_LEVEL_UP;
  int requiredTimeInMinutes = 0;
  int XPIncrement = A;
  int boostTime = 0;
  while (currentXP < requiredXP)
  {
    if (V > 0 && boostTime == 0)
    {
      XPIncrement = C;
      boostTime = 30;
      V--;
    }
    else if (S > 0 && boostTime == 0)
    {
      XPIncrement = B;
      boostTime = 30;
      S--;
    }
    else if (boostTime == 0)
    {
      XPIncrement = A;
    }

    currentXP += XPIncrement;
    boostTime = max(0, boostTime - 1);
    requiredTimeInMinutes++;
  }

  cout << requiredTimeInMinutes << '\n';
  return 0;
}