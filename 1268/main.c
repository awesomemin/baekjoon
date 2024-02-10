#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
	int numOfStudents;
	scanf("%d", &numOfStudents);
	
	int **table = (int **)malloc(sizeof(int*) * numOfStudents);
	for(int i = 0; i < numOfStudents; i++) {
		table[i] = (int *)malloc(sizeof(int) * 5);
	}
	
	for(int i = 0; i < numOfStudents; i++) {
		scanf("%d %d %d %d %d", &table[i][0], &table[i][1], &table[i][2], &table[i][3], &table[i][4]);
	}
	
	int *score = (int *)malloc(sizeof(int) * numOfStudents);
	memset(score, 0, sizeof(int) * numOfStudents);
	
	for(int i = 0; i < numOfStudents; i++) {
		for(int j = 0; j < numOfStudents; j++) {
			if(i == j)
				continue;
			for(int g = 0; g < 5; g++) {
				if(table[i][g] == table[j][g]) {
					score[i]++;
					break;
				}
			}
		}
	}
	
	int max = 0;
	for(int i = 0; i < numOfStudents; i++) {
		if(score[i] > max)
			max = score[i];
	}
	
	for(int i = 0; i < numOfStudents; i++) {
		if(score[i] == max) {
			printf("%d\n", i + 1);
			break;
		}
	}
}