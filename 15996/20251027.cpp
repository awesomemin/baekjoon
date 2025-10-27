#include <iostream>
using namespace std;

int main()
{
  int N, A;
  cin >> N >> A;

  int k = 0;
  while (N >= 1)
  {
    k = k + N / A;
    N = N / A;
  }

  cout << k << '\n';

  return 0;
}