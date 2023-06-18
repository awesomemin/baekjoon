#include <iostream>
#include <cstring>

double convert(char * grade) {
	if(strcmp(grade, "A+") == 0) {
		return 4.5;
	} else if(strcmp(grade, "A0") == 0) {
		return 4.0;
	} else if(strcmp(grade, "B+") == 0) {
		return 3.5;
	} else if(strcmp(grade, "B0") == 0) {
		return 3.0;
	} else if (strcmp(grade, "C+") == 0) {
		return 2.5;
	} else if (strcmp(grade, "C0") == 0) {
		return 2.0;
	} else if (strcmp(grade, "D+") == 0) {
		return 1.5;
	} else if (strcmp(grade, "D0") == 0) {
		return 1.0;
	} else if (strcmp(grade, "F") == 0) {
		return 0.0;
	}
	return 10000.0;
}

int main() {
	char course_name[60];
	double hakjum;
	char grade[4];
	
	double total_hakjum = 0.0;
	double total_grade_times_hakjum = 0.0;
	
	for(int i = 0; i < 20; i++) {
		std::cin >> course_name >> hakjum >> grade;
		double converted_grade = convert(grade);
		if(strcmp(grade, "P") == 0) {
			continue;
		} else {
			total_hakjum += hakjum;
			total_grade_times_hakjum += (converted_grade * hakjum);
		}
	}
	
	std::cout << (total_grade_times_hakjum / total_hakjum) << std::endl;
	
	return 0;
}