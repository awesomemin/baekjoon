#include <iostream>
#include <vector>
using namespace std;

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int map[751][751];
  int rightBorder = N - 1;
  int leftBorder = 0;
  int upBorder = 0;
  int downBorder = N - 1;
  int direction = 0; // 0:right, 1:down, 2:left, 3:up
  int x = 0;
  int y = 0;
  int num = 1;
  while (1)
  {
    if (direction == 0)
    {
      while (x < rightBorder)
      {
        map[y][x] = num++;
        x++;
      }
      upBorder++;
      direction = 1;
    }
    else if (direction == 1)
    {
      while (y < downBorder)
      {
        map[y][x] = num++;
        y++;
      }
      rightBorder--;
      direction = 2;
    }
    else if (direction == 2)
    {
      while (x > leftBorder)
      {
        map[y][x] = num++;
        x--;
      }
      downBorder--;
      direction = 3;
    }
    else if (direction == 3)
    {
      while (y > upBorder)
      {
        map[y][x] = num++;
        y--;
      }
      leftBorder++;
      direction = 0;
    }

    if (num >= N * N)
    {
      break;
    }
  }

  map[y][x] = num;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << map[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}