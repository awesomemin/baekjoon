#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isAFormer(const string &A, const string &B)
{
  for (int i = 0; i < min(A.size(), B.size()); i++)
  {
    if (A[i] < B[i])
      return true;
    else if (A[i] > B[i])
      return false;
  }
  if (A.size() > B.size())
    return false;
  else
    return true;
}

string modifyString(const string &str, int cut1, int cut2)
{
  string word1, word2, word3;
  word1 = str.substr(0, cut1 + 1);
  word2 = str.substr(cut1 + 1, cut2 - cut1);
  word3 = str.substr(cut2 + 1);
  reverse(word1.begin(), word1.end());
  reverse(word2.begin(), word2.end());
  reverse(word3.begin(), word3.end());
  return word1 + word2 + word3;
}

int main()
{
  string result;
  string word;
  cin >> word;
  for (int i = 0; i < word.size() - 2; i++)
  {
    for (int j = i + 1; j < word.size() - 1; j++)
    {
      string modifiedString = modifyString(word, i, j);
      if (result == "" || isAFormer(modifiedString, result))
      {
        result = modifiedString;
      }
    }
  }
  cout << result << '\n';
  return 0;
}