#include <iostream>
#include <queue>
using namespace std;

long long A, B;

long long depth = 0;

queue<long long> q;

long long op1(long long num) {return num * 2;};

long long op2(long long num) {return (num * 10) + 1;};

int main(void) {
	cin>>A>>B;
	
	q.push(A);
	q.push(-1);
	bool minusOne = false;
	long long num;
	while(!q.empty()) {
		num = q.front();
		q.pop();
		if(num > B) {
			continue;
		}
		if(minusOne && num == -1) {
			break;
		}
		if(num == -1) {
			depth++;
			q.push(-1);
			minusOne = true;
			continue;
		} else {
			minusOne = false;
		}
		if(num == B) {
			cout<<depth + 1<<endl;
			break;
		}
		q.push(op1(num));
		q.push(op2(num));
	}
	if(num == -1) {
		cout<<-1<<endl;
	}
	
	return 0;
}