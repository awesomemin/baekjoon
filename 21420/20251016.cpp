#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int coin;
  int H = 0, T = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> coin;
    if (coin == 1)
      H++;
    else
      T++;
  }

  cout << ((H > T) ? T : H) << '\n';

  return 0;
}