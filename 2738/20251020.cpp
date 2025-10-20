#include <iostream>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  int Matrix[100][100];
  for(int y = 0; y < N; y++) {
    for(int x = 0; x < M; x++) {
      int elem;
      cin >> elem;
      Matrix[y][x] = elem;
    }
  }
  for(int y = 0; y < N; y++) {
    for(int x = 0; x < M; x++) {
      int elem;
      cin >> elem;
      Matrix[y][x] += elem;
    }
  }
  for(int y = 0; y < N; y++) {
    for(int x = 0; x < M; x++) {
      cout << Matrix[y][x] << " ";
    }
    cout << "\n";
  }

  return 0;
}