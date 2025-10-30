#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  vector<int> edges;
  int tempEdge;
  for (int i = 0; i < N; i++)
  {
    cin >> tempEdge;
    edges.push_back(tempEdge);
  }
  sort(edges.begin(), edges.end(), greater<int>());
  int result = -1;
  for (int i = 0; i <= edges.size() - 3; i++)
  {
    if (edges[i] < edges[i + 1] + edges[i + 2])
    {
      result = edges[i] + edges[i + 1] + edges[i + 2];
      break;
    }
  }
  cout << result << '\n';
  return 0;
}