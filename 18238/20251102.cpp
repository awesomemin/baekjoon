#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
  string str;
  cin >> str;
  char currentChar = 'A';
  int time = 0;
  for (int i = 0; i < str.size(); i++)
  {
    time += min(abs(str[i] - currentChar), (90 - (max(currentChar, str[i])) + min(currentChar, str[i]) - 65 + 1));
    currentChar = str[i];
  }
  cout << time << '\n';
  return 0;
}