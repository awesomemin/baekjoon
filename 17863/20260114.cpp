#include <iostream>

int main()
{
  int N;
  std::cin >> N;
  if (N / 10000 == 555)
  {
    std::cout << "YES";
  }
  else
  {
    std::cout << "NO";
  }

  return 0;
}