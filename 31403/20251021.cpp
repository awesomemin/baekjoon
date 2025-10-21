#include <iostream>
#include <string>

using namespace std;

int main() {
  int A, B, C;
  string Astr, Bstr, Cstr;

  cin >> A >> B >> C;
  cout << A + B - C << "\n";
  Astr = to_string(A);
  Bstr = to_string(B);
  cout << stoi(Astr + Bstr) - C;

  return 0;
}