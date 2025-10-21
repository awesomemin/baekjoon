#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<char, string> oct2bin;
  oct2bin['0'] = "000";
  oct2bin['1'] = "001";
  oct2bin['2'] = "010";
  oct2bin['3'] = "011";
  oct2bin['4'] = "100";
  oct2bin['5'] = "101";
  oct2bin['6'] = "110";
  oct2bin['7'] = "111";
  string num;
  cin >> num;
  string result;
  for(int i = 0; i < num.length(); i++) {
    result += oct2bin[num[i]];
  }
  int index = result.find_first_not_of('0');
  result.erase(0, index);
  if(result.length() == 0) {
    cout << 0;
  } else {
    cout << result;
  }
  return 0;
}