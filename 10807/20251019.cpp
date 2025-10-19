#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  scanf("%d", &N);

  vector<int> vec(N);

  for(int i = 0; i < N; i++) {
    scanf("%d", &vec[i]);
  }

  int v, result = 0;
  scanf("%d", &v);
  for(int i = 0; i < N; i++) {
    if(vec[i] == v) result++;
  }
  printf("%d\n", result);

  return 0;
}