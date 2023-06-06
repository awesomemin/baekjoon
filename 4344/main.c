#include <stdio.h>
#include <stdlib.h>

int getAvr(int arr[], int n) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return (sum / n);
}

int main() {
	int C;
	scanf("%d", &C);
	
	for(int i = 0; i < C; i++) {
		int N;
		scanf("%d", &N);
		int * students = (int*)malloc(sizeof(int) * N);
		for(int j = 0; j < N; j++) {
			int score;
			scanf("%d", &score);
			students[j] = score;
		}
		int avr = getAvr(students, N);
		int studentsAboveAvr = 0;
		for(int j = 0; j < N; j++) {
			if(students[j] > avr) {
				studentsAboveAvr++;
			}
		}
		printf("%.3f% \n", ((double)(studentsAboveAvr) / (double)(N)) * 100);
		
	}
}