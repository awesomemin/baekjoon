#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  string word;
  cin >> word;
  vector<char> row15;
  vector<char> row24;
  vector<char> row3;

  row15.push_back('.');
  row15.push_back('.');
  for (int i = 0; i < word.size(); i++)
  {
    if (i % 3 == 2)
    {
      row15.push_back('*');
    }
    else
    {
      row15.push_back('#');
    }
    for (int j = 0; j < 3; j++)
    {
      if (i == word.size() - 1)
        break;
      row15.push_back('.');
    }
  }
  row15.push_back('.');
  row15.push_back('.');

  row24.push_back('.');
  for (int i = 0; i < word.size(); i++)
  {
    if (i % 3 == 2)
    {
      row24.push_back('*');
      row24.push_back('.');
      row24.push_back('*');
    }
    else
    {
      row24.push_back('#');
      row24.push_back('.');
      row24.push_back('#');
    }
    row24.push_back('.');
  }
  row24.push_back('.');

  for (int i = 0; i < word.size(); i++)
  {
    if (i % 3 == 0)
    {
      if (i == 0)
        row3.push_back('#');
      row3.push_back('.');
      row3.push_back(word[i]);
      row3.push_back('.');
      row3.push_back('#');
    }
    else if (i % 3 == 1)
    {
      row3.push_back('.');
      row3.push_back(word[i]);
      row3.push_back('.');
      row3.push_back('#');
    }
    else if (i % 3 == 2)
    {
      row3.pop_back();
      row3.push_back('*');

      row3.push_back('.');
      row3.push_back(word[i]);
      row3.push_back('.');
      row3.push_back('*');
    }
  }

  for (int i = 0; i < row15.size(); i++)
  {
    cout << row15[i];
  }
  cout << '\n';
  for (int i = 0; i < row24.size(); i++)
  {
    cout << row24[i];
  }
  cout << '\n';
  for (int i = 0; i < row3.size(); i++)
  {
    cout << row3[i];
  }
  cout << '\n';
  for (int i = 0; i < row24.size(); i++)
  {
    cout << row24[i];
  }
  cout << '\n';
  for (int i = 0; i < row15.size(); i++)
  {
    cout << row15[i];
  }

  return 0;
}