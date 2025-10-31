#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> memoization;
  memoization.push_back(0); // 0원 => 동전 0개
  memoization.push_back(1); // 1원 => 동전 1개
  memoization.push_back(1); // 2원 => 동전 1개
  memoization.push_back(2); // 3원 => 동전 2개
  memoization.push_back(2); // 4원 => 동전 2개
  memoization.push_back(1); // 5원 => 동전 1개
  memoization.push_back(2); // 6원 => 동전 2개
  memoization.push_back(1); // 7원 => 동전 1개

  for (int i = 8; i <= N; i++)
  {
    memoization.push_back(min({memoization[i - 1], memoization[i - 2], memoization[i - 5], memoization[i - 7]}) + 1);
  }

  cout << memoization[N] << '\n';

  return 0;
}