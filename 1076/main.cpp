#include <stdio.h>
#include <cstring>
#include <cmath>

long colorToValue(char * color) {
	if(strcmp(color, "black") == 0)
		return 0;
	else if(strcmp(color, "brown") == 0)
		return 1;
	else if(strcmp(color, "red") == 0)
		return 2;
	else if(strcmp(color, "orange") == 0)
		return 3;
	else if(strcmp(color, "yellow") == 0)
		return 4;
	else if(strcmp(color, "green") == 0)
		return 5;
	else if(strcmp(color, "blue") == 0)
		return 6;
	else if(strcmp(color, "violet") == 0)
		return 7;
	else if(strcmp(color, "grey") == 0)
		return 8;
	else if(strcmp(color, "white") == 0)
		return 9;
	else
		return -1;
}

int main() {
	char color[7];
	long resistance;
	
	for(int i = 0; i < 3; i++) {
		scanf("%s", color);
		if(i == 0) {
			resistance = colorToValue(color) * 10;
		} else if(i == 1) {
			resistance += colorToValue(color);
		} else if(i == 2) {
			resistance = resistance * long(pow(10, colorToValue(color)));
		}
	}
	
	printf("%ld\n", resistance);
	return 0;
}