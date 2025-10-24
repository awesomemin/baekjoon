#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  char Player;
  cin >> Player;

  vector<string> Board;
  for (int i = 0; i < 3; i++)
  {
    string row;
    cin >> row;
    Board.push_back(row);
  }

  int Count = 0;
  int Empty = 0;
  int EmptyPosition = 0;
  for (int i = 0; i < 3; i++)
  {
    if (Board[i][i] == Player)
      Count++;
    if (Board[i][i] == 'E')
    {
      Empty++;
      EmptyPosition = i;
    }
  }

  if (Count == 2 && Empty == 1)
  {
    cout << EmptyPosition + 1 << ' ' << EmptyPosition + 1 << '\n';
    return 0;
  }

  Count = 0;
  Empty = 0;
  for (int i = 0; i < 3; i++)
  {
    if (Board[i][2 - i] == Player)
      Count++;
    if (Board[i][2 - i] == 'E')
    {
      Empty++;
      EmptyPosition = i;
    }
  }

  if (Count == 2 && Empty == 1)
  {
    cout << EmptyPosition + 1 << ' ' << 3 - EmptyPosition << '\n';
    return 0;
  }

  for (int i = 0; i < 3; i++)
  {
    Count = 0;
    Empty = 0;
    for (int j = 0; j < 3; j++)
    {
      if (Board[i][j] == Player)
        Count++;
      if (Board[i][j] == 'E')
      {
        Empty++;
        EmptyPosition = j;
      }
    }
    if (Count == 2 && Empty == 1)
    {
      cout << i + 1 << ' ' << EmptyPosition + 1 << '\n';
      return 0;
    }
  }

  for (int i = 0; i < 3; i++)
  {
    Count = 0;
    Empty = 0;
    for (int j = 0; j < 3; j++)
    {
      if (Board[j][i] == Player)
        Count++;
      if (Board[j][i] == 'E')
      {
        Empty++;
        EmptyPosition = j;
      }
    }
    if (Count == 2 && Empty == 1)
    {
      cout << EmptyPosition + 1 << ' ' << i + 1 << '\n';
      return 0;
    }
  }

  return 0;
}