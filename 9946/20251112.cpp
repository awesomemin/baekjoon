#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  string str1, str2;
  int caseNum = 1;
  cin >> str1 >> str2;
  while (str1 != "END" && str2 != "END")
  {
    bool isSame = true;
    cin >> str1 >> str2;
    vector<int> s1(26);
    vector<int> s2(26);
    for (int i = 0; i < sizeof(str1); i++)
    {
      s1[str1[i] - 'a']++;
    }
    for (int i = 0; i < sizeof(str2); i++)
    {
      s2[str2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
      if (s1[i] != s2[i])
      {
        isSame = false;
        break;
      }
    }
    cout << "Case " << caseNum++ << ": " << (isSame ? "same" : "different") << '\n';
  }

  return 0;
}