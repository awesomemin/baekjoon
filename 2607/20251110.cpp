#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
  vector<int> word1(26);
  int N;
  cin >> N;
  int result = 0;
  for (int i = 0; i < N; i++)
  {
    string word;
    cin >> word;
    vector<int> word2(26);
    for (int j = 0; j < word.size(); j++)
    {
      if (i == 0)
      {
        word1[word[j] - 'A']++;
      }
      else
      {
        word2[word[j] - 'A']++;
      }
    }
    int word1big = 0;
    int word2big = 0;
    for (int j = 0; j < 26; j++)
    {
      if (word1[j] == word2[j])
        continue;
      else if (word1[j] - word2[j] == 1)
      {
        word1big++;
      }
      else if (word1[j] - word2[j] == -1)
      {
        word2big++;
      }
      else
      {
        word1big += 999;
      }
    }
    if (i != 0 && ((word1big == 1 && word2big == 0) || (word1big == 0 && word2big == 1) || (word1big == 1 && word2big == 1) || (word1big == 0 && word2big == 0)))
      result++;
  }
  cout << result;

  return 0;
}