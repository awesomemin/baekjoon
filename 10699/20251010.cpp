#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main(void) {
  time_t timestamp;
  time(&timestamp);
  tm* localTime = localtime(&timestamp);
  int year = localTime->tm_year + 1900;
  int month = localTime->tm_mon + 1;
  int day = localTime->tm_mday;
  cout << setfill('0');
  cout << year << "-" << setw(2) << month << "-" << setw(2) << day << "\n";
  return 0;
}