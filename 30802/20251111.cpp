#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  vector<int> Demand(6);
  int T, P;
  cin >> N;
  for (int i = 0; i < 6; i++)
  {
    cin >> Demand[i];
  }
  cin >> T >> P;
  int A = 0, B = 0, C = 0;
  for (int i = 0; i < 6; i++)
  {
    if (Demand[i] % T == 0)
    {
      A += Demand[i] / T;
    }
    else
    {
      A += Demand[i] / T + 1;
    }
  }
  cout << A << '\n'
       << N / P << ' ' << N % P << '\n';
  return 0;
}