#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int h, m;
    cin >> h >> m;

    vector<string> numbers = {"",
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
        "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "half"
    };

    int nextH = h % 12 + 1;

    if (m == 0) {
        cout << numbers[h] << " o' clock" << '\n';
    } else if(m == 1) {
        cout << numbers[m] << " minute past " << numbers[h] << '\n';
    } else if(m == 15 || m == 30) {
        cout << numbers[m] << " past " << numbers[h] << '\n';
    } else if(m < 30) {
        cout << numbers[m] << " minutes past " << numbers[h] << '\n';
    } else if(m == 45) {
        cout << numbers[60 - m] << " to " << numbers[nextH] << '\n';
    } else if(m == 59) {
        cout << numbers[60 - m] << " minute to " << numbers[nextH] << '\n';
    } else {
        cout << numbers[60 - m] << " minutes to " << numbers[nextH] << '\n';
    }
    
    return 0;
}