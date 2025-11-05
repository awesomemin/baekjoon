#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;

  string seal;
  cin >> seal;

  vector<int> v(10);

  for (int i = 0; i < N; i++)
  {
    switch (seal[i])
    {
    case 'R':
      v[0]++;
      break;
    case 'E':
      v[1]++;
      break;
    case 'B':
      v[2]++;
      break;
    case 'O':
      v[3]++;
      break;
    case 'N':
      v[4]++;
      break;
    case 'Z':
      v[5]++;
      break;
    case 'S':
      v[6]++;
      break;
    case 'I':
      v[7]++;
      break;
    case 'L':
      v[8]++;
      break;
    case 'V':
      v[9]++;
      break;
    }
  }

  v[0] /= 2;
  v[1] /= 2;

  cout << *min_element(v.begin(), v.end());

  return 0;
}