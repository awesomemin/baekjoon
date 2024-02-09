#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	typedef struct _student {
		char name[15];
		int day;
		int month;
		int year;
	} Student;
	
	Student * students = new Student[n];
	
	for(int i = 0; i < n; i++) {
		Student new_student;
		cin >> new_student.name >> new_student.day >> new_student.month >> new_student.year;
		students[i] = new_student;
	}
	
	int oldest_year = 2011;
	int youngest_year = 1989;
	
	int oldest_month = 13;
	int youngest_month = 0;
	
	for(int i = 0; i < n; i++) {
		if(students[i].year < oldest_year) {
			oldest_year = students[i].year;
		}
		
		if(students[i].year > youngest_year) {
			youngest_year = students[i].year;
		}
	}
	
	stack<Student> oldest_year_targets;
	stack<Student> youngest_year_targets;
	
	for(int i = 0; i < n; i++) {
		if(students[i].year == oldest_year) {
			oldest_year_targets.push(students[i]);
		}
		if(students[i].year == youngest_year) {
			youngest_year_targets.push(students[i]);
		}
	}
	
	while(!oldest_year_targets.empty()) {
		Student temp = oldest_year_targets.pop();
		cout << temp.name << " ";
	}
	
	return 0;
}