#include <iostream>
using namespace std;

int main()
{
  long long n;
  cin >> n;
  long long result = 0;
  while (n >= 1)
  {
    result += n * (n + 1) / 2;
    n--;
  }
  cout << result << '\n';
  return 0;
}