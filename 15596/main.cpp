#include <iostream>
#include <vector>
using namespace std;

long long sum(vector<int> &a) {
	long long rt = 0;
	for(int i = 0; i < a.size(); i++) {
		rt += a[i];
	}
	return rt;
}